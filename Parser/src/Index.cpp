#include "../includes/Index.h"

Index::Index() {
  this->exp = NULL;
  this->type = NOTYPE;
}

void Index::addNode(Exp* exp){
  this->exp = exp;
}

Exp* Index::getExp(){
  return exp;
}

NodeType Index::getType(){
  return this->type;
}

void Index::typeCheck(){
  if (getError()) {
    return;
  }
  exp->typeCheck();
  if (exp->getType() == ERROR) {
    this->type = ERROR;
  } else {
    this->type = ARRAY;
  }
}

void Index::makeCode(std::ofstream &code){
  exp->makeCode(code);
  code << "ADD\n";
}

Index::~Index() {
  delete exp;
}
