#include "../includes/StatementAssign.h"

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
        index->typeCheck();
        if (identifier->getType() == NOTYPE) {
                cerr << "Error: Line: " << identifier->getLine() << " Column: " << identifier->getColumn() << " Identifier is not defined.\n";
                this->type = ERROR;
                setError();
        } else if ((exp->getType() == INT
                    && (identifier->getType() == INT && index->getType() == NOTYPE)
                    || (identifier->getType() == INTARRAY && index->getType() == ARRAY))) {
                this->type = NOTYPE;
        } else {
                cerr << "Error: Line: " << identifier->getLine() << " Column: " << identifier->getColumn() << " Types are incompatible.\n";
                this->type = ERROR;
                setError();
        }
}

void StatementAssign::makeCode(std::ofstream &code){
        exp->makeCode(code);
        code << "LA " << "$" << identifier->getLexem() << "\n";
        index->makeCode(code);
        code << "STR" << "\n";
}


StatementAssign::~StatementAssign() {
        delete identifier;
        delete index;
        delete exp;
}
