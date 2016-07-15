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

void Automat::Handle(char c){
  _state->Handle(char c);
}
