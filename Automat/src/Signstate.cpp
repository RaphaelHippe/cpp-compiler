/*
 * Signstate.cpp
 *
 *  Created on: Jul 9, 2016
 *  Author: Raphael Hippe
 */

#include "../includes/Signstate.h"


Signstate::Signstate(Automat* context) {
	// TODO Auto-generated constructor stub
  _context = context;
}

Signstate::~Signstate() {
	// TODO Auto-generated destructor stub
}

void Signstate::handle(char c){
  // logic of the state....

  // set next state:
  // _context->setState( new Signstate(_context));
}
