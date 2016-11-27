#include "../includes/Signstate.h"

Signstate::Signstate() {
  one = '0';
  two = '0';
}

Signstate::~Signstate() {
}

int Signstate::handle(char c){
  // logic of the state....

  // einteilige Zeichen
  if (c == '+' || c == '-' || c == '<' || c == '>' || c == '(' || c == ')' ||
      c == '{' || c == '}' || c == '[' || c == ']' || c == '!' || c == ';') {
        // check if its the first sign or 2nd one
        if (one == '0') {
          // first one
          one = c;
          return 1;
        } else {
          // second one
          return 0;
        }

  // mehrteilige Zeichen
  } else {
    // switch (c) {
    //   case ':':
    //     if (one == '0') {
    //       one = c;
    //       return 1;
    //     } else if(one == '='){
    //       return 1;
    //     } else {
    //       return 0;
    //     }
    //   case '*':
    //     if (one == '0') {
    //       one = c;
    //       return 1;
    //     } else {
    //       return 0;
    //     }
    //   case '=':
    //     if (one == '0') {
    //       one = c;
    //       return 1;
    //     } else {
    //       return -1;
    //     }
    //   case '&':
    //     if (one == '0') {
    //       one = c;
    //       return 1;
    //     } else if (one == '&') {
    //       one = '0';
    //       return 0;
    //     } else {
    //       return -1;
    //     }
    //   default:
    //     return -1;
    // }
    return -1;
  }

}
