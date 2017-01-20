/*
 * Automat.h
 *
 *  Created on: Jan 20, 2017
 *      Author: Raphael Hippe
 */

#pragma once

#include "Leaf.h"
#include "./../../Symboltable/includes/Token.h"

#ifndef Identifier_H_
#define Identifier_H_

class Identifier : public Leaf {
private:
  Token* token;
public:
  Identifier(Token* token);
  virtual ~Identifier();
};

#endif /* Identifier_H_ */
