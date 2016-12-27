#include "../includes/Automat.h"
#include <cstddef>
#include <iostream>
using namespace std;

Automat::Automat() {
  _state = INIT;
  _tokenState = INIT;
  // TODO: check if _column starts at 0 or 1?!
  // TODO: Why does it work with _column being 2 here and 1 on new line ...?!
  _column = 1;
  // TODO: check if _line starts at 0 or 1?!
  _line = 1;
}

Automat::~Automat() {
}

void Automat::setState(int stateresult) {
  switch (stateresult) {
    // TODO: DELETE this and move to checkLexem()
    case 24:
    case 21:
    case 20:
    case 0:
      _state = INIT;
      break;
    case 10:
      _state = INTEGER;
      _tokenState = INTEGER;
      break;
    case 11:
      _state = IDENTIFIER;
      _tokenState = IDENTIFIER;
      break;
    case 12:
      _state = SIGN;
      _tokenState = SIGN;
      break;
    case 14:
      _state = NEWLINE;
      // _tokenState = NEWLINE;
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
      _column = 1;
      _line++;
      stateresult = 21;
      break;
  }
  setState(stateresult);

  if (stateresult == 23) {
    // new line in comment
    _column = 1;
    _line++;
  }

  if (stateresult != 0 && stateresult != 14 &&
    stateresult != -99 && stateresult != 23) {
        // cout << "\nstateresult: " << stateresult << " char: " << c << "\n";
    _column++;
  }
  // cout << "Automat Stateresult: " << stateresult << "\n";
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
  States myState = _tokenState;
  _tokenState = INIT;
  return myState;
}
int Automat::getline(){
  return _line;
}
int Automat::getcolumn(){
  return _column;
}
void Automat::decreaseColumn(){
  _column--;
}
// int Automat::getvalue(){
//   return 1;
// }
// Information* Automat::getinformation(){
//   return NULL;
// }
