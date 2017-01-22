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
  NodeType type;
public:
  Op(Token* token);
  virtual void addNode();
  std::string getLexem();
  int getLine();
  int getColumn();
  NodeType getType();
  void typeCheck();
  void makeCode(std::ofstream &code);
};

#endif /* Op_H_ */
