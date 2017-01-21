#include "../includes/ExpIINegative.h"
#include <iostream>

using namespace std;
ExpIINegative::ExpIINegative() {
  this->expII = NULL;
  this->type = NOTYPE;
}

void ExpIINegative::addNode(ExpII* expII){
  this->expII = expII;
}

ExpII* ExpIINegative::getExpII(){
  return expII;
}

NodeType ExpIINegative::getType(){
  return this->type;
}

void ExpIINegative::typeCheck(){
  if (getError()) {
    return;
  }
  expII->typeCheck();
  this->type = expII->getType();
}

void ExpIINegative::makeCode(){

}

ExpIINegative::~ExpIINegative() {
  delete expII;
}
