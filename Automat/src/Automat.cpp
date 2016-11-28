#include "../includes/Automat.h"
#include <cstddef>

Automat::Automat() {
  _state = INIT;
}

Automat::~Automat() {
}

void Automat::setState(int stateresult) {
  switch (stateresult) {
    // TODO: DELETE this and move to checkLexem()
    case 0: _state = INIT;
    break;
    case 10: _state = INTEGER;
    break;
    case 11: _state = IDENTIFIER;
    break;
    case 12: _state = SIGN;
    break;
  }
}

int Automat::handle(char c){
  int stateresult = 0;
  switch (_state) {
    case INIT:
    stateresult = initstate.handle(c);
    break;
    case INTEGER:
    stateresult = integerstate.handle(c);
    break;
    case IDENTIFIER:
    stateresult = identifierstate.handle(c);
    break;
    case SIGN:
    stateresult = signstate.handle(c);
    break;
  }
  setState(stateresult);

  // wenn stateresult != 0 bauen wir am aktuellem lexem weiter, wenn 0 dann nicht
  // if (stateresult != 0) {
  //   return 1;
  // } else {
  //   return 0;
  // }
  return stateresult;
}

// TODO: IF und WHILE handlen (checkLexem())

// TODO: getter für Token richtig bauen

//
// int Automat::gettype(){
//   return 1;
// }
// int Automat::getline(){
//   return 1;
// }
// int Automat::getcolumn(){
//   return 1;
// }
// int Automat::getvalue(){
//   return 1;
// }
// Information* Automat::getinformation(){
//   return NULL;
// }
