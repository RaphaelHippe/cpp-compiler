/*
 * Automat.h
 *
 *  Created on: Jan 20, 2017
 *      Author: Raphael Hippe
 */

#pragma once

#include "ExpIIExp.h"
#include "ExpII.h"
#include "Identifier.h"
#include "Index.h"

#ifndef ExpIIIndex_H_
#define ExpIIIndex_H_

class ExpIIIndex : public ExpII {
private:
  Identifier* identifier;
  Index* index;
  NodeType type;
public:
  ExpIIIndex();
  void addNode(Identifier* identifier);
  void addNode(Index* index);
  Identifier* getIdentifier();
  Index* getIndex();
  NodeType getType();
  void typeCheck();
  void makeCode(std::ofstream &code);
  virtual ~ExpIIIndex();
};

#endif /* ExpIIIndex_H_ */
