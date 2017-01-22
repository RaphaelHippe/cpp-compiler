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
  NodeType type;
public:
  Exp();
  void addNode(ExpII* expII);
  void addNode(OpExp* opExp);
  ExpII* getExpII();
  OpExp* getOpExp();
  NodeType getType();
  void typeCheck();
  void makeCode(std::ofstream &code);
  virtual ~Exp();
};

#endif /* Exp_H_ */
