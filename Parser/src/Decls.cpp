#include "../includes/Decls.h"
#include <iostream>

using namespace std;
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

void Decls::makeCode(){

}

Decls::~Decls() {
  delete decl;
  delete decls;
}
