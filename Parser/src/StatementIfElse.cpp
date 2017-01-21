#include "../includes/StatementIfElse.h"
#include <iostream>

using namespace std;
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

void StatementIfElse::makeCode(){

}


StatementIfElse::~StatementIfElse() {
  delete exp;
  delete statement1;
  delete statement2;
}
