#pragma once
/*
 * Automat.h
 *
 *  Created on: Jan 20, 2017
 *      Author: Raphael Hippe
 */


#include "Node.h"
#include "ExpII.h"
#include "OpExp.h"

#ifndef Exp_H_
#define Exp_H_

class OpExp;

class Exp : public Node {
private:
  ExpII* expII;
  OpExp* opExp;
public:
  Exp();
  void addNode(ExpII* expII);
  void addNode(OpExp* opExp);
  void typeCheck();
  void makeCode();
  virtual ~Exp();
};

#endif /* Exp_H_ */
