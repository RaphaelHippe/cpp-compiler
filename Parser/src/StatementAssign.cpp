#include "../includes/StatementAssign.h"
#include <iostream>

using namespace std;
StatementAssign::StatementAssign() {
  // _context = context;
}

void StatementAssign::addNode(Identifier* identifier){
  this->identifier = identifier;
}

void StatementAssign::addNode(Index* index){
  this->index = index;
}

void StatementAssign::addNode(Exp* exp){
  this->exp = exp;
}

void StatementAssign::typeCheck(){

}

void StatementAssign::makeCode(){

}


StatementAssign::~StatementAssign() {
}
