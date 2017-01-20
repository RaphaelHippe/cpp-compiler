/*
 * Automat.h
 *
 *  Created on: Jan 20, 2017
 *      Author: Raphael Hippe
 */
#pragma once

#include "Node.h"
#include "Decls.h"
#include "Statements.h"

#ifndef Prog_H_
#define Prog_H_

class Prog : public Node {
private:
  Decls* decls;
  Statements* statements;
public:
  Prog();
  virtual ~Prog();

  void addNode(Decls* decls);
  void addNode(Statements* statements);
  void typeCheck();
  void makeCode();
};

#endif /* Prog_H_ */