#include "../includes/Identifierstate.h"
#include <ctype.h>


Identifierstate::Identifierstate() {
	// TODO Auto-generated constructor stub
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
int Identifierstate::handle(char c){
  if (isdigit(c) || isalpha(c)) {
    return 1;
  } else {
    return 0;
  }
}
