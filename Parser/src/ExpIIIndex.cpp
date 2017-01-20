#include "../includes/ExpIIIndex.h"
#include <iostream>

using namespace std;
ExpIIIndex::ExpIIIndex() {
  // _context = context;
}

void ExpIIIndex::addNode(Identifier* identifier){
  this->identifier = identifier;
}

void ExpIIIndex::addNode(Index* index){
  this->index = index;
}

void ExpIIIndex::typeCheck(){

}

void ExpIIIndex::makeCode(){

}


ExpIIIndex::~ExpIIIndex() {
}
