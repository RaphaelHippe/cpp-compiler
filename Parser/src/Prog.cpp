#include "../includes/Prog.h"
#include <iostream>

using namespace std;
Prog::Prog() {
  // _context = context;
}

void Prog::addNode(Decls* decls){
  this->decls = decls;
}

void Prog::addNode(Statements* statements){
  this->statements = statements;
}

void Prog::typeCheck(){

}

void Prog::makeCode(){

}


Prog::~Prog() {
}
