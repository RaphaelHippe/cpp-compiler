#include "../includes/Automat.h"
#include <cstddef>
#include <iostream>
using namespace std;

Automat::Automat() {
  _state = INIT;
  // TODO: check if _column starts at 0 or 1?!
  _column = 1;
  // TODO: check if _column starts at 0 or 1?!
  _line = 0;
}

Automat::~Automat() {
}

void Automat::setState(int stateresult) {
  switch (stateresult) {
    // TODO: DELETE this and move to checkLexem()
    case 21:
    case 20:
    case 0: _state = INIT;
    break;
    case 10: _state = INTEGER;
    break;
    case 11: _state = IDENTIFIER;
    break;
    case 12: _state = SIGN;
    break;
    case 14: _state = NEWLINE;
    break;
    default:
    break;
  }
}

int Automat::handle(char c){
  int stateresult = 0;

  if (_state == INIT) {
    stateresult = initstate.handle(c);
    setState(stateresult);
  }
  switch (_state) {
    case INTEGER:
    stateresult = integerstate.handle(c);
    break;
    case IDENTIFIER:
    stateresult = identifierstate.handle(c);
    break;
    case SIGN:
    stateresult = signstate.handle(c);
    break;
    case NEWLINE:
      _column = 0;
      _line++;
      stateresult = 0;
      break;
  }
  setState(stateresult);
  if (stateresult != 0) {
    _column ++;
  }
  if (c == '\n') {
    cout << "NEW LINE \n";
    cout << "state " << _state << "\n";
    _line++;
    // _column = 0;
    // stateresult = 0;
  }
  return stateresult;
}

int Automat::checkLexem(char s[]){
  // _state = INIT;
  // return 1;
  // if, IF,
  // while, WHILE
  // &&
  // int result = 0;
  //
  // if (_state == INTEGER) {
  //   // bau nen Iteger
  // }
  //
  // if (_state == IDENTIFIER) {
  //   // bau nen Identifier
  //   if (s == 'while' || s == 'WHILE') {
  //     // baue WHILE lexem
  //   } else if (s == 'if' || s == 'IF') {
  //     // baue IF Lexem
  //   } else {
  //     // baue normales Lexem
  //   }
  //
  // }
  //
  // if (_state == SIGN) {
  //   /* code */
  //   if (s[0] == '&') {
  //     if (s[1] == '&') {
  //       //bau Lexem
  //     } else {
  //       //s[0] --> Error
  //     }
  //   }
  // }
  //
  // // if (_state == ERROR) {
  // //   /* code */
  // // }
  //
  // _state == INIT;
  // return result;
}

// TODO: IF und WHILE handlen (checkLexem())

// TODO: getter für Token richtig bauen

//
int Automat::gettype(){
  return _state;
}
int Automat::getline(){
  return _line;
}
int Automat::getcolumn(){
  int myColumn = _column;
  _column = 1;
  return myColumn;
}
// int Automat::getvalue(){
//   return 1;
// }
// Information* Automat::getinformation(){
//   return NULL;
// }
