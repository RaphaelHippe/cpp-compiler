/*
 * Automat.h
 *
 *  Created on: Jan 20, 2017
 *      Author: Raphael Hippe
 */

#pragma once

#include "Node.h"
#include "Statement.h"

#ifndef Statements_H_
#define Statements_H_

class Statements : public Node {
private:
  Statement* statement;
  Statements* statements;
  NodeType type;
public:
  Statements();
  void addNode(Statement* statement);
  void addNode(Statements* statements);
  Statement* getStatement();
  Statements* getStatements();
  virtual NodeType getType();
  virtual void typeCheck();
  virtual void makeCode();
  virtual ~Statements();
};

#endif /* Statements_H_ */
