/*
 * Automat.h
 *
 *  Created on: Jan 20, 2017
 *      Author: Raphael Hippe
 */

#pragma once

#include "ExpII.h"
#include "IntegerN.h"

#ifndef ExpIIInteger_H_
#define ExpIIInteger_H_

class ExpIIInteger : public ExpII {
private:
  IntegerN* integer;
public:
  ExpIIInteger();
  void addNode(IntegerN* integer);
  void typeCheck();
  void makeCode();
  virtual ~ExpIIInteger();
};

#endif /* ExpIIInteger_H_ */
