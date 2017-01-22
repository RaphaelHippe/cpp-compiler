#include "../includes/Parsetree.h"

Parsetree::Parsetree(Prog* prog) {
  this->prog = prog;
}

bool Parsetree::typeCheck(){
  prog->typeCheck();
  return prog->getError();
}

void Parsetree::makeCode(std::string codePath){
  code.open(codePath.c_str());
  prog->makeCode(code);
}

Parsetree::~Parsetree() {
  delete prog;
  code.close();
}
