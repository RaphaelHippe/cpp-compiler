/*
 * Automat.h
 *
 *  Created on: Jan 20, 2017
 *      Author: Raphael Hippe
 */

#pragma once

#include "Node.h"

#ifndef Statement_H_
#define Statement_H_

class Statement : public Node {
private:
public:
  virtual void addNode();
  virtual void typeCheck();
  virtual NodeType getType();
  virtual void makeCode();
};

#endif /* Statement_H_ */
