/*
 * Automat.h
 *
 *  Created on: Jan 20, 2017
 *      Author: Raphael Hippe
 */

#pragma once

#include "Statement.h"
#include "Statements.h"

#ifndef StatementBracket_H_
#define StatementBracket_H_

class StatementBracket : public Statement {
private:
  Statements* statements;
public:
  StatementBracket();
  void addNode(Statements* statements);
  void typeCheck();
  void makeCode();
  virtual ~StatementBracket();
};

#endif /* StatementBracket_H_ */
