/*
 * Entry.cpp
 *
 *  Created on: Jul 17, 2016
 *      Author: Raphael Hippe
 */

#include "../includes/Entry.h"
#include "../includes/Information.h"
#include <stdio.h>

Entry::Entry(Information* value) {
	// TODO Auto-generated constructor stub
  myValue = value;
  myNext = NULL;
}

Entry::~Entry() {
	// TODO Auto-generated destructor stub
}

int Entry::addValue(Information* value){
  if (myNext == NULL) {
    // If there is no next element -> create another
    myNext = new Entry(value);
    return 1;
  } else {
    // if there is a next element do another
    return myNext->addValue(value) + 1;
  }
}

Information* Entry::getValue(int position){
  if (position == 0) {
    // If position equals 0 return myValue
    return myValue;
  } else {
    // if position is not 0 get the value of next with position -1
    return myNext->getValue(position - 1);
  }
}
