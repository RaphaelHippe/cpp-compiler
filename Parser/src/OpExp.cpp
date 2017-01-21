#include "../includes/OpExp.h"
#include <iostream>

using namespace std;
OpExp::OpExp() {
        this->op = NULL;
        this->exp = NULL;
        this->type = NOTYPE;
}

void OpExp::addNode(Op* op){
        this->op = op;
}

void OpExp::addNode(Exp* exp){
        this->exp = exp;
}

Exp* OpExp::getExp(){
        return exp;
}

Op* OpExp::getOp(){
        return op;
}

NodeType OpExp::getType(){
        return this->type;
}

void OpExp::typeCheck(){
        if (getError()) {
                return;
        }
        op->typeCheck();
        if (getError) {
                return;
        }
        exp->typeCheck();
        this->type = exp->getType();
}

void OpExp::makeCode(){

}


OpExp::~OpExp() {
        delete op;
        delete exp;
}
