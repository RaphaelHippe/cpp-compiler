/*
 * Identifierstate.cpp
 *
 *  Created on: Jul 9, 2016
 *  Author: Raphael Hippe
 */

#include "../includes/Identifierstate.h"


Identifierstate::Identifierstate(Automat* context) {
	// TODO Auto-generated constructor stub
  _context = context;
}

Identifierstate::~Identifierstate() {
	// TODO Auto-generated destructor stub
}

void Identifierstate::Handle(){
  // logic of the state....

  // set next state:
  // _context->setState( new Signstate(_context));
}
