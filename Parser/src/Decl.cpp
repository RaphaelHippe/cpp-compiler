#include "../includes/Decl.h"
#include <iostream>

using namespace std;
Decl::Decl() {
  // _context = context;
}

void Decl::addNode(Arr* arr){
  this->arr = arr;
}

void Decl::addNode(Identifier* identifier){
  this->identifier = identifier;
}

void Decl::typeCheck(){

}

void Decl::makeCode(){

}

Decl::~Decl() {
}
