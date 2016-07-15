/*
 * Automat.h
 *
 *  Created on: Jul 9, 2016
 *      Author: Raphael Hippe
 */

#ifndef State_H_
#define State_H_

class State {
public:
  virtual void Handle(char c) = 0;
}

#endif /* State_H_ */
