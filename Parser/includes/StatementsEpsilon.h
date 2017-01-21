/*
 * Automat.h
 *
 *  Created on: Jan 20, 2017
 *      Author: Raphael Hippe
 */

#pragma once

#include "Statements.h"

#ifndef StatementsEpsilon_H_
#define StatementsEpsilon_H_

class StatementsEpsilon : public Statements {
private:
  NodeType type;
public:
  StatementsEpsilon();
  void typeCheck();
  void makeCode();
};

#endif /* StatementsEpsilon_H_ */
