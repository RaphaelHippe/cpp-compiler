/*
 * Buffer.h
 *
 *  Created on: Sep 26, 2012
 *      Author: knad0001
 */

#ifndef BUFFER_H_
#define BUFFER_H_

class Buffer {
private:
	static const int SIZE = 8192; // TODO: Why?
	char* buffer1;
	char* buffer2;
	char* position;
	int currentBuffer;
	int file;
	bool nextBufferLoaded;

	void allocateMemory();
	void fillBuffer(int i_buffer);
public:
	Buffer(const char* filename);
	virtual ~Buffer();

	char getChar();
	void stepBack(int steps);
};

#endif /* BUFFER_H_ */
