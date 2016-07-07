/*
 * Buffer.cpp
 *
 *  Created on: Sep 26, 2012
 *      Author: knad0001
 */

#include "../includes/Buffer.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>


Buffer::Buffer(const char* filename) {
	// TODO Auto-generated constructor stub
  file = open(filename, O_RDONLY | O_SYNC | O_DIRECT);
  if (file == -1) {
    perror("Buffer open file");
    exit(EXIT_FAILURE);
  }
  // init Buffer
  this->currentBuffer = 1;
  allocateMemory();
  this->position = buffer1;
  this->nextBufferLoaded = false;

  // Fill first Buffer
  fillBuffer(1);

}

Buffer::~Buffer() {
	// TODO Auto-generated destructor stub
  if (buffer1 != 0) {
    delete[] buffer1;
    buffer1 = 0;
  }
  if (buffer2 != 0) {
    delete[] buffer2;
    buffer2 = 0;
  }
  close(file);
}


/*
*
* Returns the next char in the buffer
* Returns '\0' at end of file
*
*/
char Buffer::getChar(){
  // If pointer is at the end of one buffer
  if ((*position) == '\0') {
    // at the end of buffer1 fill buffer2 and set pointer to buffer2
    if (position == &buffer1[SIZE]) {
      // check if already filled
      if (!nextBufferLoaded) {
        fillBuffer(2);
      }
      nextBufferLoaded = false;
      position = buffer2;
    } else if (position == &buffer2[SIZE]) {
      // at the end of buffer 2 fill buffer1 and set pointer to buffer1
      // Check if already filled
      if (!nextBufferLoaded) {
        fillBuffer(1);
      }
      nextBufferLoaded = false;
      position = buffer1;
    }
  }
  // Save char
  char c = *position;
  position++;
  return c;

}

/*
*
* The buffer takes a step back
*
*/
void Buffer::stepBack(int steps){
  while (steps > 0) {
    // Pointer at the beginning of buffer1
    if (position == buffer1) {
      // Check if you can go back this far
      if (!nextBufferLoaded) {
        position = &buffer2[SIZE - 1];
        nextBufferLoaded = true;
      } else {
        perror("Buffer step back");
        exit(EXIT_FAILURE);
      }
    }
    // Pointer at the beginning of buffer2
    else if (position == buffer2) {
      // Check if you can go back this far
      if (!nextBufferLoaded) {
        position = &buffer1[SIZE - 1];
        nextBufferLoaded = true;
      } else {
        perror("Buffer step back");
        exit(EXIT_FAILURE);
      }
    }
    // Pointer not at the beginning of any buffer
    else {
      position--;
    }
    steps--;
  }
}

/*
*
* Fills given Buffer with data from the file
*
*/
void Buffer::fillBuffer(int i_buffer){
  char* buffer;
  // select buffer to fill with data
  if (i_buffer == 1) {
    buffer = buffer1;
  } else {
    buffer = buffer2;
  }

  // read the file
  ssize_t actualSize = read(file, buffer, SIZE);

  // if less bytes are read than requested its at the end of the file
  // add '\0' after the last read char
  if (actualSize != SIZE) {
    buffer[actualSize] = '\0';
  }
}

/*
*
* Allocates Memory for the two buffer arrays according to the alignment rule.
*
*/
void Buffer::allocateMemory(){
  if (posix_memalign((void**)&buffer1, SIZE, SIZE+1) != 0 || posix_memalign((void**)&buffer2, SIZE, SIZE+1) != 0) {
    perror("Buffer posix_memalign");
    exit(EXIT_FAILURE);
  }
  memset(buffer1, 0, SIZE + 1);
  memset(buffer2, 0, SIZE + 1);
}
