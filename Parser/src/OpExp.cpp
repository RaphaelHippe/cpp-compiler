#include "../includes/OpExp.h"
#include <iostream>

using namespace std;
OpExp::OpExp() {
  // _context = context;
}

void OpExp::addNode(Op* op){
  this->op = op;
}

void OpExp::addNode(Exp* exp){
  this->exp = exp;
}

void OpExp::typeCheck(){

}

void OpExp::makeCode(){

}


OpExp::~OpExp() {
}
