/*
 * Automat.h
 *
 *  Created on: Jan 20, 2017
 *      Author: Raphael Hippe
 */

#pragma once

#include "Index.h"

#ifndef IndexEpsilon_H_
#define IndexEpsilon_H_

class IndexEpsilon : public Index {
private:
public:
  IndexEpsilon();
  void typeCheck();
  void makeCode();
  virtual ~IndexEpsilon();
};

#endif /* IndexEpsilon_H_ */