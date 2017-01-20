#include "../includes/Decls.h"
#include <iostream>

using namespace std;
Decls::Decls() {
  // _context = context;
}

void Decls::addNode(Decl* decl){
  this->decl = decl;
}

void Decls::addNode(Decls* decls){
  this->decls = decls;
}

void Decls::typeCheck(){
 
}

void Decls::makeCode(){

}

Decls::~Decls() {
}
