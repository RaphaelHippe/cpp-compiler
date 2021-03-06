#include "../includes/Exp.h"

Exp::Exp() {
        this->expII = NULL;
        this->opExp = NULL;
        this->type = NOTYPE;
}

void Exp::addNode(ExpII* expII){
        this->expII = expII;
}

void Exp::addNode(OpExp* opExp){
        this->opExp = opExp;
}

ExpII* Exp::getExpII(){
        return expII;
}

OpExp* Exp::getOpExp(){
        return opExp;
}

NodeType Exp::getType(){
        return this->type;
}


void Exp::typeCheck(){
        if (getError()) {
                return;
        }
        expII->typeCheck();
        if (getError()) {
                return;
        }
        opExp->typeCheck();
        if (opExp->getType() == NOTYPE) {
                this->type = expII->getType();
        } else if (expII->getType() != opExp->getType()) {
                this->type = ERROR;
        } else {
                this->type = expII->getType();
        }
}

void Exp::makeCode(std::ofstream &code){
        if (opExp->getType() == NOTYPE) {
                expII->makeCode(code);
        } else if (opExp->getOp()->getType() == OPGREATER) {
                opExp->makeCode(code);
                expII->makeCode(code);
                code << "LES\n";
        } else if (opExp->getOp()->getType() == OPUNEQUAL) {
                expII->makeCode(code);
                opExp->makeCode(code);
                code << "NOT\n";
        } else {
                expII->makeCode(code);
                opExp->makeCode(code);
        }
}

Exp::~Exp() {
        delete expII;
        delete opExp;
}
