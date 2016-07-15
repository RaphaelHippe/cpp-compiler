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

/*
* Integerstate needs to check whether the Integer is build further or not
* Check if c is an Integer if yes, stay in this state, if not go to Initstate
*/
void Integerstate::Handle(char c){
  if (isdigit(c)) {
    /* stay in Integerstate */
  } else {
    _context->setState( new Initstate(_context));
  }
}
