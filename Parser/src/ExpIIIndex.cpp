#include "../includes/ExpIIIndex.h"
#include <iostream>

using namespace std;
ExpIIIndex::ExpIIIndex() {
        this->identifier = NULL;
        this->index = NULL;
        this->type = NOTYPE;
}

void ExpIIIndex::addNode(Identifier* identifier){
        this->identifier = identifier;
}

void ExpIIIndex::addNode(Index* index){
        this->index = index;
}

Identifier* ExpIIIndex::getIdentifier(){
        return identifier;
}

Index* ExpIIIndex::getIndex(){
        return index;
}

NodeType ExpIIIndex::getType(){
        return this->type;
}

void ExpIIIndex::typeCheck(){
        if (getError()) {
                return;
        }
        index->typeCheck();
        if (identifier->getType() == NOTYPE) {
                cerr << "Error: Line: " << identifier->getLine() << " Column: " << identifier->getColumn() << " Identifier not defined.\n";
                this->type = ERROR;
                setError();
        } else if (identifier->getType() == INT && index->getType() == NOTYPE) {
                this->type = identifier->getType();
        } else if (identifier->getType() == INTARRAY && index->getType() == ARRAY) {
                this->type = INT;
        } else {
                cerr << "Error: Line: " << identifier->getLine() << " Column: " << identifier->getColumn() << " No primitive type.\n";
                this->type = ERROR;
                setError();
        }
}

void ExpIIIndex::makeCode(){

}

ExpIIIndex::~ExpIIIndex() {
        delete identifier;
        delete index;
}
