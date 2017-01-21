#include "../includes/Decls.h"

Decls::Decls() {
        this->decl = NULL;
        this->decls = NULL;
        this->type = NOTYPE;
}

void Decls::addNode(Decl* decl){
        this->decl = decl;
}

void Decls::addNode(Decls* decls){
        this->decls = decls;
}

Decl* Decls::getDecl(){
        return decl;
}

Decls* Decls::getDecls(){
        return decls;
}

NodeType Decls::getType(){
        return this->type;
}

void Decls::typeCheck(){
        if (getError()) {
                return;
        }
        decl->typeCheck();
        if (getError()) {
                return;
        }
        decls->typeCheck();
}

void Decls::makeCode(std::ofstream &code){
  decl->makeCode(code);
  decls->makeCode(code);
}

Decls::~Decls() {
  delete decl;
  delete decls;
}
