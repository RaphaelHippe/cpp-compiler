/*
 * Automat.h
 *
 *  Created on: Jan 20, 2017
 *      Author: Raphael Hippe
 */

#pragma once

#include "Leaf.h"
#include "./../../Symboltable/includes/Token.h"

#ifndef IntegerN_H_
#define IntegerN_H_

class IntegerN : public Leaf {
private:
  Token* token;
public:
  IntegerN(Token* token);
  virtual ~IntegerN();
};

#endif /* IntegerN_H_ */
