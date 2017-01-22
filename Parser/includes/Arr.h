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
  NodeType type;
public:
  Arr();
  void addNode(IntegerN* integer);
  IntegerN* getInteger();
  virtual NodeType getType();
  virtual void typeCheck();
  virtual void makeCode(std::ofstream &code);
  virtual ~Arr();
};

#endif /* Arr_H_ */
