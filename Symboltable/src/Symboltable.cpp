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

void Symboltable::initSymbols(){
  Information* whileInfo = new Information("while");
  whileInfo->setType(Token::WHILE);
  Information* WHILEInfo = new Information("WHILE");
  WHILEInfo->setType(Token::WHILE);
  Information* ifInfo = new Information("if");
  ifInfo->setType(Token::IF);
  Information* IFInfo = new Information("IF");
  IFInfo->setType(Token::IF);
  Information* readInfo = new Information("read");
  readInfo->setType(Token::READ);
  Information* writeInfo = new Information("write");
  writeInfo->setType(Token::WRITE);
  Information* elseInfo = new Information("else");
  elseInfo->setType(Token::ELSE);
  Information* ELSEInfo = new Information("ELSE");
  ELSEInfo->setType(Token::ELSE);
  Information* intInfo = new Information("int");
  intInfo->setType(Token::INT);

  Information* plusInfo = new Information("+");
  plusInfo->setType(Token::PLUS);
  Information* minusInfo = new Information("-");
  minusInfo->setType(Token::MINUS);
  Information* starInfo = new Information("*");
  starInfo->setType(Token::STAR);
  Information* colonInfo = new Information(":");
  colonInfo->setType(Token::COLON);
  Information* smallerInfo = new Information("<");
  smallerInfo->setType(Token::SMALLER);
  Information* greaterInfo = new Information(">");
  greaterInfo->setType(Token::GREATER);
  Information* equalsInfo = new Information("=");
  equalsInfo->setType(Token::EQUALS);
  Information* assignmentInfo = new Information(":=");
  assignmentInfo->setType(Token::ASSIGNMENT);
  Information* weirdthingInfo = new Information("=:=");
  weirdthingInfo->setType(Token::WEIRDTHING);
  Information* exmarkInfo = new Information("!");
  exmarkInfo->setType(Token::EXMARK);
  Information* andandInfo = new Information("&&");
  andandInfo->setType(Token::ANDAND);
  Information* semicolonInfo = new Information(";");
  semicolonInfo->setType(Token::SEMICOLON);
  Information* bracketopenInfo = new Information("(");
  bracketopenInfo->setType(Token::BRACKETOPEN);
  Information* bracketcloseInfo = new Information(")");
  bracketcloseInfo->setType(Token::BRACKETCLOSE);
  Information* curlybracketopenInfo = new Information("{");
  curlybracketopenInfo->setType(Token::CURLYBRACKETOPEN);
  Information* curlybracketcloseInfo = new Information("}");
  curlybracketcloseInfo->setType(Token::CURLYBRACKETCLOSE);
  Information* squarebracketopenInfo = new Information("[");
  squarebracketopenInfo->setType(Token::SQUAREBRACKETOPEN);
  Information* squarebracketcloseInfo = new Information("]");
  squarebracketcloseInfo->setType(Token::SQUAREBRACKETCLOSE);

  this->insert(whileInfo);
  this->insert(WHILEInfo);
  this->insert(ifInfo);
  this->insert(IFInfo);
  this->insert(readInfo);
  this->insert(writeInfo);
  this->insert(elseInfo);
  this->insert(ELSEInfo);
  this->insert(intInfo);
  this->insert(plusInfo);
  this->insert(minusInfo);
  this->insert(starInfo);
  this->insert(colonInfo);
  this->insert(smallerInfo);
  this->insert(greaterInfo);
  this->insert(equalsInfo);
  this->insert(assignmentInfo);
  this->insert(weirdthingInfo);
  this->insert(exmarkInfo);
  this->insert(andandInfo);
  this->insert(semicolonInfo);
  this->insert(bracketopenInfo);
  this->insert(bracketcloseInfo);
  this->insert(curlybracketopenInfo);
  this->insert(curlybracketcloseInfo);
  this->insert(squarebracketopenInfo);
  this->insert(squarebracketcloseInfo);
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

Key* Symboltable::testInsert(Information* value, int testHashValue){
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
