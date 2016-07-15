/*
 * Automat.h
 *
 *  Created on: Jul 9, 2016
 *      Author: Raphael Hippe
 */

#ifndef Integerstate_H_
#define Integerstate_H_

class Integerstate: public State {
private:
  Automat* _context;
public:
  Integerstate(Automat* context);
  void Handle(char c);
}

#endif /* Integerstate_H_ */
