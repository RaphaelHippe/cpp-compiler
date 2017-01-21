/*
 * Automat.h
 *
 *  Created on: Jan 20, 2017
 *      Author: Raphael Hippe
 */

#pragma once

#include "Node.h"
#include "Prog.h"
#include "NodeTypes.h"
#include <fstream>


#ifndef Parsetree_H_
#define Parsetree_H_

class Parsetree {
private:
  Prog* prog;
  std::ofstream code;
public:
  Parsetree(Prog* prog);
  bool typeCheck();
  void makeCode(std::string codePath);
  virtual ~Parsetree();
};

#endif /* Parsetree_H_ */
