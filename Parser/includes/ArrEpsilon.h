/*
 * Automat.h
 *
 *  Created on: Jan 20, 2017
 *      Author: Raphael Hippe
 */

#pragma once

#include "Arr.h"

#ifndef ArrEpsilon_H_
#define ArrEpsilon_H_

class ArrEpsilon : public Arr {
private:
  NodeType type;
public:
  ArrEpsilon();
  void typeCheck();
  void makeCode(std::ofstream &code);
};

#endif /* Arr_H_ */
