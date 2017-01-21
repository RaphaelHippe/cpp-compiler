#include "../includes/StatementWrite.h"
#include <iostream>

using namespace std;
StatementWrite::StatementWrite() {
  this->exp = NULL;
  this->type = NOTYPE;
}

void StatementWrite::addNode(Exp* exp){
  this->exp = exp;
}

Exp* StatementWrite::getExp(){
  return exp;
}

NodeType StatementWrite::getType(){
  return this->type;
}

void StatementWrite::typeCheck(){
  if (getError()) {
    return;
  }
  exp->typeCheck();
}

void StatementWrite::makeCode(){

}

StatementWrite::~StatementWrite() {
  delete exp;
}
