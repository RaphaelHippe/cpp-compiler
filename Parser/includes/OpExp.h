#pragma once
/*
 * Automat.h
 *
 *  Created on: Jan 20, 2017
 *      Author: Raphael Hippe
 */


#include "Node.h"
#include "Exp.h"
#include "Op.h"

#ifndef OpExp_H_
#define OpExp_H_

class Exp;

class OpExp : public Node{
private:
  Exp* exp;
  Op* op;
public:
  OpExp();
  void addNode(Op* op);
  void addNode(Exp* exp);
  virtual void typeCheck();
  virtual void makeCode();
  virtual ~OpExp();
};

#endif /* OpExp_H_ */