#include "../includes/ExpIINot.h"

ExpIINot::ExpIINot() {
        this->expII = NULL;
        this->type = NOTYPE;
}

void ExpIINot::addNode(ExpII* expII){
        this->expII = expII;
}

ExpII* ExpIINot::getExpII(){
        return expII;
}

NodeType ExpIINot::getType(){
        return this->type;
}

void ExpIINot::typeCheck(){
        if (getError()) {
                return;
        }
        expII->typeCheck();
        if (expII->getType() != INT) {
                this->type = ERROR;
        } else {
                this->type = INT;
        }
}

void ExpIINot::makeCode(std::ofstream &code){
  expII->makeCode(code);
  code << "NOT\n";
}

ExpIINot::~ExpIINot() {
        delete expII;
}
