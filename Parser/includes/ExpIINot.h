/*
 * Automat.h
 *
 *  Created on: Jan 20, 2017
 *      Author: Raphael Hippe
 */

#pragma once

#include "ExpII.h"

#ifndef ExpIINot_H_
#define ExpIINot_H_

class ExpIINot : public ExpII {
private:
  ExpII* expII;
public:
  ExpIINot();
  void addNode(ExpII* expII);
  void typeCheck();
  void makeCode();
  virtual ~ExpIINot();
};

#endif /* ExpIINot_H_ */
