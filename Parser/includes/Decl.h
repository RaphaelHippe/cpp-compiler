/*
 * Automat.h
 *
 *  Created on: Jan 20, 2017
 *      Author: Raphael Hippe
 */
#pragma once

#include "Node.h"
#include "Arr.h"
#include "Identifier.h"

#ifndef Decl_H_
#define Decl_H_

class Decl : public Node{
private:
  Arr* arr;
  Identifier* identifier;
public:
  Decl();
  void addNode(Arr* arr);
  void addNode(Identifier* identifier);
  void typeCheck();
  void makeCode();
  virtual ~Decl();
};

#endif /* Decl_H_ */
