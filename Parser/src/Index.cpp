#include "../includes/Index.h"
#include <iostream>

using namespace std;
Index::Index() {
  // _context = context;
}

void Index::addNode(Exp* exp){
  this->exp = exp;
}

void Index::typeCheck(){

}

void Index::makeCode(){

}


Index::~Index() {
}
