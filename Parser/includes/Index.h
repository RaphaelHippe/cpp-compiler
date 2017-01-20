/*
 * Automat.h
 *
 *  Created on: Jan 20, 2017
 *      Author: Raphael Hippe
 */

#pragma once

#include "Node.h"
#include "Exp.h"

#ifndef Index_H_
#define Index_H_

class Index : public Node {
private:
  Exp* exp;
public:
  Index();
  void addNode(Exp* exp);
  virtual void typeCheck();
  virtual void makeCode();
  virtual ~Index();
};

#endif /* Index_H_ */
