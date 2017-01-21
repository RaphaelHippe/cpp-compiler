#include "../includes/Parsetree.h"

Parsetree::Parsetree(Prog* prog) {
  this->prog = prog;
}

bool Parsetree::typeCheck(){
  prog->typeCheck();
  return prog->getError();
}

Parsetree::~Parsetree() {
}
