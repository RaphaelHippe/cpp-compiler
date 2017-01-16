#include "../includes/Initstate.h"
#include <ctype.h>
#include <iostream>

using namespace std;
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
  } else if(c == ' ') {
    // space
    return 22;
  } else if(c == '\n') {
    // new line
    // cout << "new line!";
    // cout << '\n';
    return 14;
  } else if(c == '\0') {
    // end of file
    return -99;
  } else {
    /* unknown character --> error */
    return -1;
  }
}
