/*
 * Automat.h
 *
 *  Created on: Jan 20, 2017
 *      Author: Raphael Hippe
 */

#pragma once

#include "Node.h"
#include "Prog.h"

#ifndef Parsetree_H_
#define Parsetree_H_

class Parsetree {
private:
  Prog* prog;
public:
  Parsetree(Prog* prog);
  virtual ~Parsetree();
};

#endif /* Parsetree_H_ */
