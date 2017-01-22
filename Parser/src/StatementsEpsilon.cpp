#include "../includes/StatementsEpsilon.h"

StatementsEpsilon::StatementsEpsilon() {
  this->type = NOTYPE;
}


void StatementsEpsilon::typeCheck(){
}

void StatementsEpsilon::makeCode(std::ofstream &code){
  code << "NOP\n";
}
