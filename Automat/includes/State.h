/*
 * Automat.h
 *
 *  Created on: Jul 9, 2016
 *      Author: Raphael Hippe
 */

#pragma once
// #include "Automat.h"


#ifndef State_H_
#define State_H_

class State {
public:
  State();
  virtual ~State();
  // Automat* _context;
  virtual int handle(char c);
};

#endif /* State_H_ */
