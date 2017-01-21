/*
 * Automat.h
 *
 *  Created on: Jan 20, 2017
 *      Author: Raphael Hippe
 */

#pragma once

#include "OpExp.h"

#ifndef OpExpEpsilon_H_
#define OpExpEpsilon_H_

class OpExpEpsilon : public OpExp {
private:
  NodeType type;
public:
  OpExpEpsilon();
  void typeCheck();
  void makeCode();
};

#endif /* OpExpEpsilon_H_ */
