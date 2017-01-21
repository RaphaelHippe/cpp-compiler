/*
 * Automat.h
 *
 *  Created on: Jan 20, 2017
 *      Author: Raphael Hippe
 */

#pragma once

#include <stdio.h>
#include <fstream>
#include <iostream>
#include "NodeTypes.h"

#ifndef Node_H_
#define Node_H_

class Node {
private:
  static int labelCount;
  static bool error;
public:
  virtual void addNode();
  virtual void typeCheck();
  virtual void makeCode(std::ofstream &code);
  static int getLabelCount();
  static bool getError();
  static void setError();
};

#endif /* Node_H_ */
