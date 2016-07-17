/*
 * Symboltable.cpp
 *
 *  Created on: Sep 26, 2012
 *      Author: knad0001
 *  Edited:
 *      Author: Raphael Hippe
 */

#include "../includes/Symboltable.h"
#include <stdio.h>

Symboltable::Symboltable() {
	// TODO Auto-generated constructor stub
  table = new List [TABLE_SIZE];
  myKey = new Key();
  myHashValue = 0;
  factor = 0;
  currentChar = 'a';
}

Key* Symboltable::insert(Information* value){
  // create empty key and list
  Key* key = new Key();
  int position = 0;
  List *list = NULL;
  // calc hashValue
  myHashValue = value->calcHashValue();
  myHashValue = myHashValue % TABLE_SIZE;
  // checkout which list we need and insert value into list by chosen hashValue
  list = &table[myHashValue];
  position = list->addValue(value);
  // set key hashValue and position
  key->setHashValue(myHashValue);
  key->setEntryPosition(position);
  return key;
}

Key* Symboltable::testInsertinsert(Information* value, int testHashValue){
  // create empty key and list
  Key* key = new Key();
  int position = 0;
  List *list = NULL;
  // calc hashValue
  factor = 1;
  myHashValue = testHashValue;
  // checkout which list we need and insert value into list by chosen hashValue
  list = &table[myHashValue];
  position = list->addValue(value);
  // set key hashValue and position
  key->setHashValue(myHashValue);
  key->setEntryPosition(position);
  return key;
}

Information* Symboltable::lookup(Key *key){
  List *list = &table[key->getHashValue()];
  return list->getInformation(key->getEntryPosition());
}

Symboltable::~Symboltable() {
	// TODO Auto-generated destructor stub
  for (int i = 0; i < TABLE_SIZE; i++) {
    delete &table[i];
  }
  delete table;
}
