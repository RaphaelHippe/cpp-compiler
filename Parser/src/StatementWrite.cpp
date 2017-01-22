#include "../includes/StatementWrite.h"

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

void StatementWrite::makeCode(std::ofstream &code){
  exp->makeCode(code);
  code << "PRI\n";
}

StatementWrite::~StatementWrite() {
  delete exp;
}
