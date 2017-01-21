#include "../includes/StatementWhile.h"
#include <iostream>

using namespace std;
StatementWhile::StatementWhile() {
        this->exp = NULL;
        this->statement = NULL;
        this->type = NOTYPE;
}

void StatementWhile::addNode(Exp* exp){
        this->exp = exp;
}

void StatementWhile::addNode(Statement* statement){
        this->statement = statement;
}

Exp* StatementWhile::getExp(){
        return exp;
}

Statement* StatementWhile::getStatement(){
        return statement;
}

NodeType StatementWhile::getType(){
        return this->type;
}

void StatementWhile::typeCheck(){
        if (getError()) {
                return;
        }
        exp->typeCheck();
        if (getError()) {
                return;
        }
        statement->typeCheck();
        if (exp->getType() == ERROR) {
                this->type = ERROR;
        } else {
                this->type = NOTYPE;
        }
}

void StatementWhile::makeCode(){

}

StatementWhile::~StatementWhile() {
        delete exp;
        delete statement;
}
