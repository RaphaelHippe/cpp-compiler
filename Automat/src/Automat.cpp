/*
 * Automat.cpp
 *
 */

#include "../includes/Automat.h"


Automat::Automat() {
	// TODO Auto-generated constructor stub
  // set init state...
  _state = new Initstate(this);
}

Automat::~Automat() {
	// TODO Auto-generated destructor stub
}

void Automat::setState(State* state) {
  _state = state;
}

int Automat::handle(char c){

  if (c == '\0') {
    return Automat::UNDEFINED;
  } else {
    return Automat::INIT;
  }

  // return _state->handle(char c);
}
