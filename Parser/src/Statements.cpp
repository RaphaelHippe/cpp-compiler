#include "../includes/Statements.h"
#include <iostream>

using namespace std;
Statements::Statements() {
  // _context = context;
}

void Statements::addNode(Statement* statement){
  this->statement = statement;
}

void Statements::addNode(Statements* statements){
  this->statements = statements;
}

void Statements::typeCheck(){

}

void Statements::makeCode(){

}


Statements::~Statements() {
}
