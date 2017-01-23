#include "../includes/StatementWhile.h"

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

void StatementWhile::makeCode(std::ofstream &code){
  int label1 = getLabelCount();
  int label2 = getLabelCount();
  code << "#" << "label" << label1 << " NOP\n";
  exp->makeCode(code);
  code << "JIN " << "#" << "label" << label2 << "\n";
  statement->makeCode(code);
  code << "JMP " << "#" << "label" << label1 << "\n";
  code << "#" << "label" << label2 << " NOP\n";
}

StatementWhile::~StatementWhile() {
        delete exp;
        delete statement;
}
