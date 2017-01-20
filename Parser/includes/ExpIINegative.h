/*
 * Automat.h
 *
 *  Created on: Jan 20, 2017
 *      Author: Raphael Hippe
 */

#pragma once

#include "ExpII.h"

#ifndef ExpIINegative_H_
#define ExpIINegative_H_

class ExpIINegative : public ExpII {
private:
  ExpII* expII;
public:
  ExpIINegative();
  void addNode(ExpII* expII);
  void typeCheck();
  void makeCode();
  virtual ~ExpIINegative();
};

#endif /* ExpIINegative_H_ */