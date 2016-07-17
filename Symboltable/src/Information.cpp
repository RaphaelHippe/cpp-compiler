/*
 * Information.cpp
 *
 *  Created on: Jul 17, 2016
 *      Author: Raphael Hippe
 */

#include "../includes/Information.h"
#include <iostream>
#include <stdio.h>

Information::Information(char word[]) {
	// TODO Auto-generated constructor stub
  for (int j = 0; j < 1024; j++) {
    lexem[j] = '\0';
  }
  int i = 0;
  while (i < 1024 || word[i] != '\0') {
    lexem[i] = word[i];
    i++;
  }
  lexemPointer = lexem;
  myType = NULL;
}

void Information::setType(int type){
  myType = type;
}

char Information::getLexemPointer(){
  return *lexemPointer;
}

void Information::incrementLexemPointer(){
  *lexemPointer++;
}

char Information::getType(){
  return myType;
}

bool Information::compairLexem(char word[]){
  int i = 0;
  while (word[i] == lexem[i]) {
    if (word[i] == '\0' || lexem[i] == '\0') {
      break;
    }
    i++;
  }
  if (word[i] == '\0' && lexem[i] == '\0') {
    return true;
  } else {
    return false;
  }
}

void Information::printLexem(){
  lexemPointer = lexem;
  while (*lexemPointer != '\0') {
    printf("%c\n", *lexemPointer);
    *lexemPointer++;
  }
  printf("%s\n", "All printed!");
}

int Information::calcHashValue(){
  int factor = 1;
  int myHashValue = 0;
  lexemPointer = lexem;
  while (*lexemPointer != '\0') {
    currentChar = *lexemPointer;
    myHashValue = myHashValue + (factor * (int)currentChar);
    factor++;
    *lexemPointer++;
  }
  return myHashValue;
}

Information::~Information() {
	// TODO Auto-generated destructor stub
}
