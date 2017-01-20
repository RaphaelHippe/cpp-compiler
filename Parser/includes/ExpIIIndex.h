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
public:
  ExpIIIndex();
  void addNode(Identifier* identifier);
  void addNode(Index* index);
  void typeCheck();
  void makeCode();
  virtual ~ExpIIIndex();
};

#endif /* ExpIIIndex_H_ */
