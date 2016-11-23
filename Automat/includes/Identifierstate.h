/*
 * Automat.h
 *
 *  Created on: Jul 9, 2016
 *      Author: Raphael Hippe
 */

#ifndef Identifierstate_H_
#define Identifierstate_H_

class Identifierstate {
private:
public:
  Identifierstate();
  virtual ~Identifierstate();
  int handle(char c);
};

#endif /* Identifierstate_H_ */
