#include "../includes/Decl.h"

Decl::Decl() {
  this->arr = NULL;
  this->identifier = NULL;
  this->type = NOTYPE;
}

void Decl::addNode(Arr* arr){
  this->arr = arr;
}

void Decl::addNode(Identifier* identifier){
  this->identifier = identifier;
}

Arr* Decl::getArr(){
  return arr;
}

Identifier* Decl::getIdentifier(){
  return identifier;
}

NodeType Decl::getType(){
  return type;
}


void Decl::typeCheck(){
  if (getError()) {
    return;
  }
  arr->typeCheck();
  if (identifier->getType() != NOTYPE) {
    cerr << "Error: Line: " << identifier->getLine() << " Column: " << identifier->getColumn() << " Identifier already defined.\n";
    this->type = ERROR;
    setError();
  } else if (arr->getType() == ERROR) {
    this->type = ERROR;
  } else {
    if (arr->getType() == ARRAY) {
      identifier->setType(INTARRAY);
    } else {
      identifier->setType(INT);
    }
  }
}

void Decl::makeCode(std::ofstream &code){
  code << "DS " << "$" << identifier->getLexem() << " ";
  arr->makeCode(code);
}

Decl::~Decl() {
  delete arr;
  delete identifier;
}
