/*
 * Automat.h
 *
 *  Created on: Jan 20, 2017
 *      Author: Raphael Hippe
 */

#pragma once

#include "ExpII.h"
#include "Exp.h"

#ifndef ExpIIExp_H_
#define ExpIIExp_H_

class ExpIIExp : public ExpII {
private:
  Exp* exp;
  NodeType type;
public:
  ExpIIExp();
  void addNode(Exp* exp);
  Exp* getExp();
  NodeType getType();
  void typeCheck();
  void makeCode();
  virtual ~ExpIIExp();
};

#endif /* ExpIIExp_H_ */
