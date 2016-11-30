/*
 * Automat.h
 *
 *  Created on: Jul 9, 2016
 *      Author: Raphael Hippe
 */

#ifndef Signstate_H_
#define Signstate_H_

class Signstate {
private:
  char one;
  char two;
  int comment;
public:
  Signstate();
  virtual ~Signstate();
  int handle(char c);
};

#endif /* Signstate_H_ */
