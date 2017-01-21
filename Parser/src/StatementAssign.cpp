#include "../includes/StatementAssign.h"
#include <iostream>

using namespace std;
StatementAssign::StatementAssign() {
        this->identifier = NULL;
        this->index = NULL;
        this->exp = NULL;
        this->type = NOTYPE;
}

void StatementAssign::addNode(Identifier* identifier){
        this->identifier = identifier;
}

void StatementAssign::addNode(Index* index){
        this->index = index;
}

void StatementAssign::addNode(Exp* exp){
        this->exp = exp;
}

Identifier* StatementAssign::getIdentifier(){
        return identifier;
}

Index* StatementAssign::getIndex(){
        return index;
}

Exp* StatementAssign::getExp(){
        return exp;
}

NodeType StatementAssign::getType(){
        return this->type;
}


void StatementAssign::typeCheck(){
        if (getError()) {
                return;
        }
        exp->typeCheck();
        if (getError()) {
                return;
        }
        if (identifier->getType() == NOTYPE) {
                cerr << "Error: Line: " << identifier->getLine() << " Column: " << identifier->getColumn() << " Identifier not defined.\n";
                this->type = ERROR;
                setError();
        } else if (exp->getType() == INT && (identifier->getType() == INT && index->getType() == NOTYPE)
                   || (identifier->getType() == INTARRAY && index->getType() == ARRAY)) {
                this->type = NOTYPE;
        } else {
                cerr << "Error: Line: " << identifier->getLine() << " Column: " << identifier->getColumn() << " Types are incompatible.\n";
                this->type = ERROR;
                setError();
        }
}

void StatementAssign::makeCode(){

}


StatementAssign::~StatementAssign() {
        delete identifier;
        delete index;
        delete exp;
}
