#include "../includes/ExpIIExp.h"
#include <iostream>

using namespace std;
ExpIIExp::ExpIIExp() {
  this->exp = NULL;
  this->type = NOTYPE;
}

void ExpIIExp::addNode(Exp* exp){
  this->exp = exp;
}

Exp* ExpIIExp::getExp(){
  return exp;
}

NodeType ExpIIExp::getType(){
  return this->type;
}


void ExpIIExp::typeCheck(){
  if (getError()) {
    return;
  }
  exp->typeCheck();
  this->type = exp->getType();
}

void ExpIIExp::makeCode(){

}


ExpIIExp::~ExpIIExp() {
  delete exp;
}
