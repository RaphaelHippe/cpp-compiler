/*
 * Automat.h
 *
 *  Created on: Jan 20, 2017
 *      Author: Raphael Hippe
 */

#pragma once

#include "Node.h"

#ifndef ExpII_H_
#define ExpII_H_

class ExpII : public Node {
private:
public:
  virtual void addNode();
  virtual NodeType getType();
  virtual void typeCheck();
  virtual void makeCode(std::ofstream &code);
};

#endif /* ExpII_H_ */
