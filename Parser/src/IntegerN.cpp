#include "../includes/IntegerN.h"
#include <iostream>

using namespace std;
IntegerN::IntegerN(Token* token) {
  this->token = token;
}

int IntegerN::getValue(){
  return token->getValue();
}

int IntegerN::getLine(){
  return token->getLine();
}

int IntegerN::getColumn(){
  return token->getColumn();
}
