#include "../includes/StatementWhile.h"
#include <iostream>

using namespace std;
StatementWhile::StatementWhile() {
  // _context = context;
}

void StatementWhile::addNode(Exp* exp){
  this->exp = exp;
}

void StatementWhile::addNode(Statement* statement){
  this->statement = statement;
}

void StatementWhile::typeCheck(){

}

void StatementWhile::makeCode(){

}


StatementWhile::~StatementWhile() {
}
