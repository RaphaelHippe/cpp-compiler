#include "../includes/Identifier.h"
#include <iostream>

using namespace std;
Identifier::Identifier(Token* token) {
  this->token = token;
}

std::string Identifier::getLexem(){
  return token->getInformation()->getLexem();
}

int Identifier::getLine(){
  return token->getLine();
}

int Identifier::getColumn(){
  return token->getColumn();
}

NodeType Identifier::getType(){
  return token->getInformation()->getNodeType();
}

void Identifier::setType(NodeType type){
  cout << "set int type\n";
  token->getInformation()->setNodeType(type);
}
