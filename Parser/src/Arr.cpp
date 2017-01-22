#include "../includes/Arr.h"

Arr::Arr() {
  this->integer = NULL;
  this->type = NOTYPE;
}

void Arr::addNode(IntegerN* integer){
    this->integer = integer;
}

IntegerN* Arr::getInteger(){
  return integer;
}

NodeType Arr::getType(){
  return type;
}

void Arr::typeCheck(){
  if (integer->getValue() > 0) {
    type = ARRAY;
  } else {
    cerr << "Error: Line: " << integer->getLine() << " Column: " << integer->getColumn() << " No valid dimension.\n";
    type = ERROR;
    setError();
  }
}

void Arr::makeCode(std::ofstream &code){
  code << integer->getValue() << "\n";
}

Arr::~Arr() {
  delete integer;
}
