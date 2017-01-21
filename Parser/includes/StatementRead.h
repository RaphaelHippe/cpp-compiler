/*
 * Automat.h
 *
 *  Created on: Jan 20, 2017
 *      Author: Raphael Hippe
 */

#pragma once

#include "Statement.h"
#include "Identifier.h"
#include "Index.h"

#ifndef StatementRead_H_
#define StatementRead_H_

class StatementRead : public Statement {
private:
  Identifier* identifier;
  Index* index;
  NodeType type;
public:
  StatementRead();
  void addNode(Identifier* identifier);
  void addNode(Index* index);
  Identifier* getIdentifier();
  Index* getIndex();
  NodeType getType();
  void typeCheck();
  void makeCode(std::ofstream &code);
  virtual ~StatementRead();
};

#endif /* StatementRead_H_ */
