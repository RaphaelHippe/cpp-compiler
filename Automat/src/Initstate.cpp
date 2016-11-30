#include "../includes/Initstate.h"
#include <ctype.h>

Initstate::Initstate() {
  // _context = context;
}

Initstate::~Initstate() {
}

/*
* Init State needs to set the Type State
* Since its the first character of any Token it will only switch to Integer-,
* Identifier- or Signstate
*/
int Initstate::handle(char c){
  if (isdigit(c)) {
    /* Character is a digit - since its a starting character, set state Integer */
    return 10;
  } else if (isalpha(c)) {
    /* Character is a letter - set Identifierstate */
    return 11;
  } else if (c == '+' || c == '-' || c == '<' || c == '>' || c == '(' || c == ')' ||
             c == '{' || c == '}' || c == '[' || c == ']' || c == '!' || c == ';' ||
             c == '&' || c == '=' || c == ':' || c == '*') {
    /* Character is a sign - set Signstate */
    return 12;
  }else if(c == ' ') {
    return 22;
  }else if(c == '\n') {
    return 14;
  } else {
    /* unknown character --> error */
    return -1;
  }
}
