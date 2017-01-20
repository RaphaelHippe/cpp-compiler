#include "../includes/ExpIIExp.h"
#include <iostream>

using namespace std;
ExpIIExp::ExpIIExp() {
  // _context = context;
}

void ExpIIExp::addNode(Exp* exp){
  this->exp = exp;
}

void ExpIIExp::typeCheck(){

}

void ExpIIExp::makeCode(){

}


ExpIIExp::~ExpIIExp() {
}
