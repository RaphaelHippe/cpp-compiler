/*
 * Automat.h
 *
 *  Created on: Jan 20, 2017
 *      Author: Raphael Hippe
 */

#pragma once

#include "Leaf.h"
#include "./../../Symboltable/includes/Token.h"

#ifndef Op_H_
#define Op_H_

class Op : Leaf {
private:
  Token* token;
public:
  Op(Token* token);
  virtual void addNode();
  void typeCheck();
  void makeCode();
  virtual ~Op();
};

#endif /* Op_H_ */
