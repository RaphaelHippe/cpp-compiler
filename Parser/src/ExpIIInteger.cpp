#include "../includes/ExpIIInteger.h"

ExpIIInteger::ExpIIInteger() {
  this->integer = NULL;
  this->type = NOTYPE;
}

void ExpIIInteger::addNode(IntegerN* integer){
  this->integer = integer;
}

IntegerN* ExpIIInteger::getInteger(){
  return integer;
}

NodeType ExpIIInteger::getType(){
  return this->type;
}

void ExpIIInteger::typeCheck(){
  this->type = INT;
}

void ExpIIInteger::makeCode(std::ofstream &code){
  code << "LC " << integer->getValue() << "\n";
}

ExpIIInteger::~ExpIIInteger() {
  delete integer;
}
