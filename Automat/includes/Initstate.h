/*
 * Automat.h
 *
 *  Created on: Jul 9, 2016
 *      Author: Raphael Hippe
 */

#ifndef Initstate_H_
#define Initstate_H_

class Initstate {
private:
public:
  Initstate();
  virtual ~Initstate();
  int handle(char c);
};

#endif /* Initstate_H_ */
