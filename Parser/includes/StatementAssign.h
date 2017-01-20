/*
 * Automat.h
 *
 *  Created on: Jan 20, 2017
 *      Author: Raphael Hippe
 */

#pragma once

#include "Statement.h"
#include "Index.h"
#include "Exp.h"
#include "Identifier.h"

#ifndef StatementAssign_H_
#define StatementAssign_H_

class StatementAssign : public Statement {
private:
  Identifier* identifier;
  Index* index;
  Exp* exp;
public:
  StatementAssign();
  void addNode(Identifier* identifier);
  void addNode(Index* index);
  void addNode(Exp* exp);
  void typeCheck();
  void makeCode();
  virtual ~StatementAssign();
};

#endif /* StatementAssign_H_ */
