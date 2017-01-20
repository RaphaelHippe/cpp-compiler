/*
 * Automat.h
 *
 *  Created on: Jan 20, 2017
 *      Author: Raphael Hippe
 */

#pragma once

#include "Node.h"
#include "IntegerN.h"

#ifndef Arr_H_
#define Arr_H_

class Arr : public Node {
private:
  IntegerN* integer;
public:
  Arr();
  void addNode(IntegerN* integer);
  void typeCheck();
  void makeCode();
  virtual ~Arr();
};

#endif /* Arr_H_ */
