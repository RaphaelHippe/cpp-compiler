/*
 * Integerstate.cpp
 *
 *  Created on: Jul 9, 2016
 *  Author: Raphael Hippe
 */

#include "../includes/Integerstate.h"
#include <ctype.h>


Integerstate::Integerstate() {
	// TODO Auto-generated constructor stub
}

Integerstate::~Integerstate() {
	// TODO Auto-generated destructor stub
}

/*
* Integerstate needs to check whether the Integer is build further or not
* Check if c is an Integer if yes, stay in this state, if not go to Initstate
*/
int Integerstate::handle(char c){
  if (isdigit(c)) {
    return 1;
  } else {
    return 0;
  }
}
