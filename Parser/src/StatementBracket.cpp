#include "../includes/StatementBracket.h"
#include <iostream>

using namespace std;
StatementBracket::StatementBracket() {
  // _context = context;
}

void StatementBracket::addNode(Statements* statements){
  this->statements = statements;
}

void StatementBracket::typeCheck(){

}

void StatementBracket::makeCode(){

}


StatementBracket::~StatementBracket() {
}
