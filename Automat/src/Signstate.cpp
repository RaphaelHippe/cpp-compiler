#include "../includes/Signstate.h"
#include <iostream>

using namespace std;

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
    // cout << "in the comment " << c << "\n";
    if (c == ':' && one == '*') {
      // raus aus Kommentar
      // cout << "exit comment " << c << "\n";
      comment = 0;
      one = '0';
      two = '0';
      return 24;
    } else {
      one = '0';
      two = '0';
    }
    if (c == '*') {
      one = c;
    }
    if (c == '\n') {
      return 23;
    }
    return 22;
  }

  // einteilige Zeichen
  if (one == '0' && two == '0') {
    switch (c) {
      case '+':
        return 30;
      break;
      case '-':
        return 31;
      break;
      case '<':
        return 34;
      break;
      case '>':
        return 35;
      break;
      case '!':
        return 39;
      break;
      case ';':
        return 41;
      break;
      case '(':
        return 42;
      break;
      case ')':
        return 43;
      break;
      case '{':
        return 44;
      break;
      case '}':
        return 45;
      break;
      case '[':
        return 46;
      break;
      case ']':
        return 47;
      break;
    }
    // if (c == '+' || c == '-' || c == '<' || c == '>' || c == '(' || c == ')' ||
    //     c == '{' || c == '}' || c == '[' || c == ']' || c == '!' || c == ';') {
    //     return 20;
    // }
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
          return 32;
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
          //TODO:CHECK!
          return 33;
        }
      case '=':
        if (one == '0') {
          one = c;
          return 1;
        } else if (one == ':') {
          one = '0';
          two = '0';
          return 37;
        } else if(one == '=' && two == ':'){
          one = '0';
          two = '0';
          return 38;
        } else {
          one = '0';
          two = '0';
          return 36;
        }
      case '&':
        if (one == '0') {
          one = c;
          return 1;
        } else if (one == '&') {
          one = '0';
          two = '0';
          return 40;
        } else {
          one = '0';
          two = '0';
          return 0;
        }
      default:
        one = '0';
        two = '0';
        return 0;
    }

}
