/*
 * Ifstate.cpp
 *
 *  Created on: Jul 9, 2016
 *  Author: Raphael Hippe
 */

#include "../includes/Ifstate.h"


Ifstate::Ifstate(Automat* context) {
	// TODO Auto-generated constructor stub
  _context = context;
}

Ifstate::~Ifstate() {
	// TODO Auto-generated destructor stub
}

void Ifstate::Handle(){
  // logic of the state....

  // set next state:
  // _context->setState( new Signstate(_context));
}
