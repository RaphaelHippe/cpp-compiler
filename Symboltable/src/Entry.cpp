/*
 * Entry.cpp
 *
 *  Created on: Jul 17, 2016
 *      Author: Raphael Hippe
 */

#include "../includes/Entry.h"
#include "../includes/Information.h"
#include <stdio.h>
#include <iostream>

using namespace std;

Entry::Entry(Information* value) {
	// TODO Auto-generated constructor stub
  myValue = value;
  myNext = NULL;
}

Entry::~Entry() {
	// TODO Auto-generated destructor stub
}

int Entry::addValue(Information* value){
  myValue->resetLexemPointer();
  value->resetLexemPointer();
  if (value->compairLexem(myValue->getLexemPointer())) {
    // return 0 since this is the entry with the same lexem
    return 0;
  } else if (myNext == NULL) {
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
