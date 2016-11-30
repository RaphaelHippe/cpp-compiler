#include "../includes/Signstate.h"

Signstate::Signstate() {
  one = '0';
  two = '0';
  comment = 0;
}

Signstate::~Signstate() {
}

int Signstate::handle(char c){
  // logic of the state....

  if (comment == 1) {
    // Im Kommentar
    if (c == ':' && one == '*') {
      // raus aus Kommentar
      comment = 0;
      one = '0';
      two = '0';
      return 21;
    } else {
      one = '0';
      two = '0';
    }
    if (c == '*') {
      one = c;
    }
    return 22;
  }

  // einteilige Zeichen
  if (one == '0' && two == '0') {
    if (c == '+' || c == '-' || c == '<' || c == '>' || c == '(' || c == ')' ||
        c == '{' || c == '}' || c == '[' || c == ']' || c == '!' || c == ';') {
        return 20;
    }
  }
  // mehrteilige Zeichen
    switch (c) {
      case ':':
        if (one == '0') {
          one = c;
          return 1;
        } else if(one == '='){
          two = c;
          return 1;
        } else {
          one = '0';
          two = '0';
          return 0;
        }
      case '*':
        if (one == '0') {
          one = c;
          return 1;
        } else if (one == ':') {
          // Kommentar beginnt!
          comment = 1;
          one = '0';
          two = '0';
          return 1;
        }{
          return 0;
        }
      case '=':
        if (one == '0') {
          one = c;
          return 1;
        } else if (one == ':' || (one == '=' && two == ':')) {
          one = '0';
          two = '0';
          return 20;
        } {
          one = '0';
          two = '0';
          return 0;
        }
      case '&':
        if (one == '0') {
          one = c;
          return 1;
        } else if (one == '&') {
          one = '0';
          two = '0';
          return 20;
        } else {
          one = '0';
          two = '0';
          return 0;
        }
      default:
        // if (one == '&') {
        //   return -1;
        // }
        one = '0';
        two = '0';
        return 0;
    }

}
