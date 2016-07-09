/*
 * Integerstate.cpp
 *
 *  Created on: Jul 9, 2016
 *  Author: Raphael Hippe
 */

#include "../includes/Integerstate.h"


Integerstate::Integerstate(Automat* context) {
	// TODO Auto-generated constructor stub
  _context = context;
}

Integerstate::~Integerstate() {
	// TODO Auto-generated destructor stub
}

void Integerstate::Handle(){
  // logic of the state....

  // set next state:
  // _context->setState( new Signstate(_context));
}
