/*
 * Automat.h
 *
 *  Created on: Jul 9, 2016
 *      Author: Raphael Hippe
 */

#include "State.h"
#include "Automat.h"

#ifndef Initstate_H_
#define Initstate_H_

class Initstate: public State {
private:
  Automat* _context;
public:
  Initstate(Automat* context);
  virtual ~Initstate();
  int handle(char c);
};

#endif /* Initstate_H_ */
