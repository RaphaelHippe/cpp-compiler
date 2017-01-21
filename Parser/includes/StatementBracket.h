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
  NodeType type;
public:
  StatementBracket();
  void addNode(Statements* statements);
  Statements* getStatements();
  NodeType getType();
  void typeCheck();
  void makeCode(std::ofstream &code);
  virtual ~StatementBracket();
};

#endif /* StatementBracket_H_ */
