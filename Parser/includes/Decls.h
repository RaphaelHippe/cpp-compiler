/*
 * Automat.h
 *
 *  Created on: Jan 20, 2017
 *      Author: Raphael Hippe
 */

#pragma once

#include "Node.h"
#include "Decl.h"

#ifndef Decls_H_
#define Decls_H_

class Decls : public Node {
private:
  Decl* decl;
  Decls* decls;
public:
  Decls();
  void addNode(Decl* decl);
  void addNode(Decls* decls);
  void typeCheck();
  void makeCode();
  virtual ~Decls();
};

#endif /* Decls_H_ */
