/*
 * Key.cpp
 *
 *  Created on: Jul 17, 2016
 *      Author: Raphael Hippe
 */

#include "../includes/Key.h"

Key::Key() {
	// TODO Auto-generated constructor stub
  myHashValue = 0;
  myEntryPosition = 0;
}

Key::~Key() {
	// TODO Auto-generated destructor stub
}

void Key::setHashValue(int hashValue){
  myHashValue = hashValue;
}

void Key::setEntryPosition(int entryPosition){
  myEntryPosition = entryPosition;
}

int Key::getHashValue(){
  return myHashValue;
}

int Key::getEntryPosition(){
  return myEntryPosition;
}
