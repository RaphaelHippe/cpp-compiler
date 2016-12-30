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
    case 30:
      _state = INIT;
      _tokenState = PLUS;
      break;
    case 31:
      _state = INIT;
      _tokenState = MINUS;
      break;
    case 32:
      _state = INIT;
      _tokenState = COLON;
      break;
    case 33:
      _state = INIT;
      _tokenState = STAR;
      break;
    case 34:
      _state = INIT;
      _tokenState = SMALLER;
      break;
    case 35:
      _state = INIT;
      _tokenState = GREATER;
      break;
    case 36:
      _state = INIT;
      _tokenState = EQUALS;
      break;
    case 37:
      _state = INIT;
      _tokenState = ASSIGNMENT;
      break;
    case 38:
      _state = INIT;
      _tokenState = WEIRDTHING;
      break;
    case 39:
      _state = INIT;
      _tokenState = EXCLAMATION;
      break;
    case 40:
      _state = INIT;
      _tokenState = ANDAND;
      break;
    case 41:
      _state = INIT;
      _tokenState = SEMICOLON;
      break;
    case 42:
      _state = INIT;
      _tokenState = STARTBRACKETA;
      break;
    case 43:
      _state = INIT;
      _tokenState = ENDBRACKETA;
      break;
    case 44:
      _state = INIT;
      _tokenState = STARTBRACKETB;
      break;
    case 45:
      _state = INIT;
      _tokenState = ENDBRACKETB;
      break;
    case 46:
      _state = INIT;
      _tokenState = STARTBRACKETC;
      break;
    case 47:
      _state = INIT;
      _tokenState = ENDBRACKETC;
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
  if (stateresult >= 30 && stateresult <= 47) {
    stateresult = 20;
    if (stateresult == 32 || stateresult == 33 || stateresult == 36) {
      stateresult = 0;
    }
  }
  if (stateresult == 23) {
    // new line in comment
    _column = 1;
    _line++;
  }

  if (stateresult != 0 && stateresult != 14 &&
      stateresult != -99 && stateresult != 23 &&
      stateresult != 21) {
    _column++;
  }
  return stateresult;
}

int Automat::gettype(){
  // States myState = _tokenState;
  // _tokenState = INIT;
  return _tokenState;
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
