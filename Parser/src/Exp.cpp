#include "../includes/Exp.h"
#include <iostream>

using namespace std;
Exp::Exp() {
  // _context = context;
}

void Exp::addNode(ExpII* expII){
  this->expII = expII;
}

void Exp::addNode(OpExp* opExp){
  this->opExp = opExp;
}

void Exp::typeCheck(){

}

void Exp::makeCode(){

}


Exp::~Exp() {
}
