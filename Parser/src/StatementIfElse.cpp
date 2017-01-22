#include "../includes/StatementIfElse.h"

StatementIfElse::StatementIfElse() {
  this->exp = NULL;
  this->statement1 = NULL;
  this->statement2 = NULL;
  this->type = NOTYPE;
}

void StatementIfElse::addNode(Exp* exp){
  this->exp = exp;
}

void StatementIfElse::addNode(Statement* statement){
  if (statement1 == NULL) {
    this->statement1 = statement;
  } else {
    this->statement2 = statement;
  }
}

Exp* StatementIfElse::getExp(){
  return exp;
}

Statement* StatementIfElse::getStatement1(){
  return statement1;
}

Statement* StatementIfElse::getStatement2(){
  return statement2;
}

NodeType StatementIfElse::getType(){
  return this->type;
}

void StatementIfElse::typeCheck(){
  if (getError()) {
    return;
  }
  exp->typeCheck();
  if (getError()) {
    return;
  }
  statement1->typeCheck();
  if (getError()) {
    return;
  }
  statement2->typeCheck();
  if (getError()) {
    return;
  }
  if (exp->getType() == ERROR) {
    this->type = ERROR;
  } else {
    this->type = NOTYPE;
  }
}

void StatementIfElse::makeCode(std::ofstream &code){
  exp->makeCode(code);
  int label1 = getLabelCount();
  int label2 = getLabelCount();
  code << "JIN " << "#" << "label" << label1 << "\n";
  statement1->makeCode(code);
  code << "JMP " << "#" << "label" << label2 << "\n";
  code << "#" << "label" << label1 << " NOP\n";
  statement2->makeCode(code);
  code << "#" << "label" << label2 << " NOP\n";
}


StatementIfElse::~StatementIfElse() {
  delete exp;
  delete statement1;
  delete statement2;
}
