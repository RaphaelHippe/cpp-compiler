/*
 * Automat.h
 *
 *  Created on: Jan 20, 2017
 *      Author: Raphael Hippe
 */

#pragma once

#include "Node.h"

#ifndef Leaf_H_
#define Leaf_H_

class Leaf : public Node {
private:
public:
  virtual void addNode();
  virtual void typeCheck();
  virtual void makeCode(std::ofstream &code);
};

#endif /* Leaf_H_ */
