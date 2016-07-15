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

/*
* Identifierstate needs to check whether the Identifier is build further or not
* Check if c is an Integer or letter if yes, stay in this state, if not go to Initstate
*
* Needs also to check for special Identifier if/IF and while/WHILE
*/
void Identifierstate::Handle(char c){
  if (isdigit(c) || isalpha(c)) {
    /* Stay in Identifierstate */
  } else {
    _context->setState( new Initstate(_context));
  }
}
