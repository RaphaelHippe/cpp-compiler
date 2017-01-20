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
public:
  StatementRead();
  void addNode(Identifier* identifier);
  void addNode(Index* index);
  void typeCheck();
  void makeCode();
  virtual ~StatementRead();
};

#endif /* StatementRead_H_ */
