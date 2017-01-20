/*
 * Automat.h
 *
 *  Created on: Jan 20, 2017
 *      Author: Raphael Hippe
 */

#pragma once

#include "Statement.h"
#include "Statements.h"
#include "Exp.h"

#ifndef StatementWrite_H_
#define StatementWrite_H_

class StatementWrite : public Statement {
private:
  Exp* exp;
public:
  StatementWrite();
  void addNode(Exp* exp);
  void typeCheck();
  void makeCode();
  virtual ~StatementWrite();
};

#endif /* StatementWrite_H_ */
