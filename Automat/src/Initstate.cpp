/*
 * Initstate.cpp
 *
 *  Created on: Jul 9, 2016
 *  Author: Raphael Hippe
 */

#include "../includes/Initstate.h"

#include <ctype.h>

Initstate::Initstate(Automat* context) {
	// TODO Auto-generated constructor stub
  _context = context;
}

Initstate::~Initstate() {
	// TODO Auto-generated destructor stub
}

/*
* Init State needs to set the Type State
* Since its the first character of any Token it will only switch to Integer-,
* Identifier- or Signstate
*/
int Initstate::handle(char c){
  if (isdigit(c)) {
    /* Character is a digit - since its a starting character, set state Integer */
    _context->setState( new Integerstate(_context));
  } else if (isalpha(c)) {
    /* Character is a letter - set Identifierstate */
    _context->setState( new Identifierstate(_context));
  } else {
    /* Character is a sign - set Signstate */
    _context->setState( new Signstate(_context));
  }
}
