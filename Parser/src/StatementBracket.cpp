#include "../includes/StatementBracket.h"

StatementBracket::StatementBracket() {
  this->statements = NULL;
  this->type = NOTYPE;
}

void StatementBracket::addNode(Statements* statements){
  this->statements = statements;
}

Statements* Statements::getStatements(){
  return statements;
}

NodeType Statements::getType(){
  return this->type;
}

void StatementBracket::typeCheck(){
  if (getError()) {
    return;
  }
  statements->typeCheck();
}

void StatementBracket::makeCode(){

}

StatementBracket::~StatementBracket() {
  delete statements;
}
