#include "../includes/StatementBracket.h"

StatementBracket::StatementBracket() {
  this->statements = NULL;
  this->type = NOTYPE;
}

void StatementBracket::addNode(Statements* statements){
  this->statements = statements;
}

Statements* StatementBracket::getStatements(){
  return statements;
}

NodeType StatementBracket::getType(){
  return this->type;
}

void StatementBracket::typeCheck(){
  if (getError()) {
    return;
  }
  statements->typeCheck();
}

void StatementBracket::makeCode(std::ofstream &code){
  statements->makeCode(code);
}

StatementBracket::~StatementBracket() {
  delete statements;
}
