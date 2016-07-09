/*
 * Whilestate.cpp
 *
 *  Created on: Jul 9, 2016
 *  Author: Raphael Hippe
 */

#include "../includes/Whilestate.h"


Whilestate::Whilestate(Automat* context) {
	// TODO Auto-generated constructor stub
  _context = context;
}

Whilestate::~Whilestate() {
	// TODO Auto-generated destructor stub
}

void Whilestate::Handle(){
  // logic of the state....

  // set next state:
  // _context->setState( new Signstate(_context));
}
