#include "../includes/StatementRead.h"
#include <iostream>

using namespace std;
StatementRead::StatementRead() {
        this->identifier = NULL;
        this->index = NULL;
        this->type = NOTYPE;
}

void StatementRead::addNode(Identifier* identifier){
        this->identifier = identifier;
}

void StatementRead::addNode(Index* index){
        this->index = index;
}

Identifier* StatementRead::getIdentifier(){
        return identifier;
}

Index* StatementRead::getIndex(){
        return index;
}

NodeType StatementRead::getType(){
        return this->type;
}

void StatementRead::typeCheck(){
        if (getError()) {
                return;
        }
        index->typeCheck();
        if (identifier->getType() == NOTYPE) {
                cerr << "Error: Line: " << identifier->getLine() << " Column: " << identifier->getColumn() << " Identifier not defined.\n";
                this->type = ERROR;
                setError();
        } else if ((identifier->getType() == INT && index->getType() == NOTYPE) ||
                   (identifier->getType() == INTARRAY && index->getType() ==ARRAY)) {
                this->type = NOTYPE;
        } else {
                cerr << "Error: Line: " << identifier->getLine() << " Column: " << identifier->getColumn() << " Types are incompatible.\n";
                this->type = ERROR;
                setError();
        }
}

void StatementRead::makeCode(){

}


StatementRead::~StatementRead() {
        delete identifier;
        delete index;
}
