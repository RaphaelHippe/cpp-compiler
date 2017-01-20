#include "../includes/StatementIfElse.h"
#include <iostream>

using namespace std;
StatementIfElse::StatementIfElse() {
  this->exp = NULL;
  this->statement1 = NULL;
  this->statement2 = NULL;
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

void StatementIfElse::typeCheck(){

}

void StatementIfElse::makeCode(){

}


StatementIfElse::~StatementIfElse() {
}
