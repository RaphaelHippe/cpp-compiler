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
  NodeType type;
public:
  Decl();
  void addNode(Arr* arr);
  void addNode(Identifier* identifier);
  Arr* getArr();
  Identifier* getIdentifier();
  NodeType getType();
  void typeCheck();
  void makeCode(std::ofstream &code);
  virtual ~Decl();
};

#endif /* Decl_H_ */
