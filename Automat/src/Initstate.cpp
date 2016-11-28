#include "../includes/Initstate.h"
#include <ctype.h>

Initstate::Initstate() {
	// TODO Auto-generated constructor stub
  // _context = context;
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
    return 10;
  } else if (isalpha(c)) {
    /* Character is a letter - set Identifierstate */
    return 11;
  } else {
    /* Character is a sign - set Signstate */
    return 12;
  }
}
