#include "../includes/ArrEpsilon.h"

ArrEpsilon::ArrEpsilon() {
  this->type = NOTYPE;
}

void ArrEpsilon::typeCheck(){

}

void ArrEpsilon::makeCode(std::ofstream &code){
  code << 1 << "\n";
}
