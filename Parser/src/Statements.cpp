#include "../includes/Statements.h"

Statements::Statements() {
  this->statement = NULL;
  this->statements = NULL;
  this->type = NOTYPE;
}

void Statements::addNode(Statement* statement){
  this->statement = statement;
}

void Statements::addNode(Statements* statements){
  this->statements = statements;
}

Statement* Statements::getStatement(){
  return statement;
}

Statements* Statements::getStatements(){
  return statements;
}

NodeType Statements::getType(){
  return this->type;
}

void Statements::typeCheck(){
  if (getError()) {
    return;
  }
  statement->typeCheck();
  if (getError()) {
    return;
  }
  statements->typeCheck();
}

void Statements::makeCode(std::ofstream &code){
  statement->makeCode(code);
  statements->makeCode(code);
}


Statements::~Statements() {
  delete statement;
  delete statements;
}
