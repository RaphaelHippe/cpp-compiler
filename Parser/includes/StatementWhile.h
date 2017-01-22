/*
 * Automat.h
 *
 *  Created on: Jan 20, 2017
 *      Author: Raphael Hippe
 */

#pragma once

#include "Statement.h"
#include "Exp.h"

#ifndef StatementWhile_H_
#define StatementWhile_H_

class StatementWhile : public Statement {
private:
  Exp* exp;
  Statement* statement;
  NodeType type;
public:
  StatementWhile();
  void addNode(Exp* exp);
  void addNode(Statement* statement);
  Exp* getExp();
  Statement* getStatement();
  NodeType getType();
  void typeCheck();
  void makeCode(std::ofstream &code);
  virtual ~StatementWhile();
};

#endif /* StatementWhile_H_ */
