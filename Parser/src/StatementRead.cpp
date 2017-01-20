#include "../includes/StatementRead.h"
#include <iostream>

using namespace std;
StatementRead::StatementRead() {
  // _context = context;
}

void StatementRead::addNode(Identifier* identifier){
  this->identifier = identifier;
}

void StatementRead::addNode(Index* index){
  this->index = index;
}

void StatementRead::typeCheck(){

}

void StatementRead::makeCode(){

}


StatementRead::~StatementRead() {
}
