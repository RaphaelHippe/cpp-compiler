#include "../includes/Op.h"

Op::Op(Token* token) {
        this->token = token;
        switch (this->token->getType()) {
        case Token::PLUS:
                this->type = OPPLUS;
                break;
        case Token::MINUS:
                this->type = OPMINUS;
                break;
        case Token::STAR:
                this->type = OPMULT;
                break;
        case Token::COLON:
                this->type = OPDIV;
                break;
        case Token::SMALLER:
                this->type = OPLESS;
                break;
        case Token::GREATER:
                this->type = OPGREATER;
                break;
        case Token::EQUALS:
                this->type = OPEQUAL;
                break;
        case Token::WEIRDTHING:
                this->type = OPUNEQUAL;
                break;
        case Token::ANDAND:
                this->type = OPAND;
                break;
        default:
                this->type = ERROR;
        }
}

void Op::addNode(){

}

std::string Op::getLexem(){
  return token->getInformation()->getLexem();
}

int Op::getLine(){
  return token->getLine();
}

int Op::getColumn(){
  return token->getColumn();
}

NodeType Op::getType(){
  return this->type;
}

void Op::typeCheck(){

}

void Op::makeCode(std::ofstream &code){
  switch (this->type) {
    case OPPLUS:
      code << "ADD\n";
      break;
    case OPMINUS:
      code << "SUB\n";
      break;
    case OPMULT:
      code << "MUL\n";
      break;
    case OPDIV:
      code << "DIV\n";
      break;
    case OPLESS:
      code << "LES\n";
      break;
    case OPGREATER:
      // code << "ADD\n";
      break;
    case OPEQUAL:
      code << "EQU\n";
      break;
    case OPUNEQUAL:
      code << "EQU\n";
      break;
    case OPAND:
      code << "AND\n";
      break;
    default:
    break;
  }
}
