/*
 * Automat.cpp
 *
 */

#include "../includes/Automat.h"


Automat::Automat() {
	// TODO Auto-generated constructor stub
  // set init state...
  // _state = new InitState(this);
}

Automat::~Automat() {
	// TODO Auto-generated destructor stub
}

void Automat::setState(State* state) {
  _state = state;
}

void Automat::Handle(){
  _state->Handle();
}
