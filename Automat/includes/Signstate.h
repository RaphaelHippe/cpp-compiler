/*
 * Automat.h
 *
 *  Created on: Jul 9, 2016
 *      Author: Raphael Hippe
 */

#ifndef Signstate_H_
#define Signstate_H_

class Signstate: public State {
private:
  Automat* _context;
public:
  Signstate(Automat* context);
  void Handle(char c);
}

#endif /* Signstate_H_ */
