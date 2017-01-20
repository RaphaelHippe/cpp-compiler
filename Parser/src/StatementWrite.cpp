#include "../includes/StatementWrite.h"
#include <iostream>

using namespace std;
StatementWrite::StatementWrite() {
  // _context = context;
}

void StatementWrite::addNode(Exp* exp){
  this->exp = exp;
}

void StatementWrite::typeCheck(){

}

void StatementWrite::makeCode(){

}


StatementWrite::~StatementWrite() {
}
