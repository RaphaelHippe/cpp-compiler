/*
 * Automat.h
 *
 *  Created on: Jul 9, 2016
 *      Author: Raphael Hippe
 */

#ifndef Integerstate_H_
#define Integerstate_H_

class Integerstate {
private:
public:
  Integerstate();
  virtual ~Integerstate();
  int handle(char c);
};

#endif /* Integerstate_H_ */
