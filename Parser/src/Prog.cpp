#include "../includes/Prog.h"
#include <iostream>

using namespace std;
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

void Prog::makeCode(){

}


Prog::~Prog() {
  delete decls;
  delete statements;
}
