/*
 * Automat.h
 *
 *  Created on: Jan 20, 2017
 *      Author: Raphael Hippe
 */

#pragma once

#include "Statement.h"
#include "Exp.h"

#ifndef StatementIfElse_H_
#define StatementIfElse_H_

class StatementIfElse : public Statement {
private:
  Exp* exp;
  Statement* statement1;
  Statement* statement2;
  NodeType type;
public:
  StatementIfElse();
  void addNode(Exp* exp);
  void addNode(Statement* statement);
  Exp* getExp();
  Statement* getStatement1();
  Statement* getStatement2();
  NodeType getType();
  void typeCheck();
  void makeCode(std::ofstream &code);
  virtual ~StatementIfElse();
};

#endif /* StatementIfElse_H_ */
