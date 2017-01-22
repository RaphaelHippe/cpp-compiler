#include "../includes/Prog.h"

Prog::Prog() {
  this->decls = NULL;
  this->statements = NULL;
  this->type = NOTYPE;
}

void Prog::addNode(Decls* decls){
  this->decls = decls;
}

void Prog::addNode(Statements* statements){
  this->statements = statements;
}

Decls* Prog::getDecls(){
  return decls;
}

Statements* Prog::getStatements(){
  return statements;
}

NodeType Prog::getType(){
  return this->type;
}

void Prog::typeCheck(){
  decls->typeCheck();
  if (getError()) {
    return;
  }
  statements->typeCheck();
}

void Prog::makeCode(std::ofstream &code){
  decls->makeCode(code);
  statements->makeCode(code);
  code << "STP";
}


Prog::~Prog() {
  delete decls;
  delete statements;
}
