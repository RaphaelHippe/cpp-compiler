#include "../includes/ExpIINot.h"
#include <iostream>

using namespace std;
ExpIINot::ExpIINot() {
  // _context = context;
}

void ExpIINot::addNode(ExpII* expII){
  this->expII = expII;
}

void ExpIINot::typeCheck(){

}

void ExpIINot::makeCode(){

}


ExpIINot::~ExpIINot() {
}
