/*
 * Signstate.cpp
 *
 *  Created on: Jul 9, 2016
 *  Author: Raphael Hippe
 */

#include "../includes/Signstate.h"


Signstate::Signstate() {
	// TODO Auto-generated constructor stub
  one = '0';
  two = '0';
}

Signstate::~Signstate() {
	// TODO Auto-generated destructor stub
}

int Signstate::handle(char c){
  // logic of the state....

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
