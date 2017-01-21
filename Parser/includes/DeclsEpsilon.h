/*
 * Automat.h
 *
 *  Created on: Jan 20, 2017
 *      Author: Raphael Hippe
 */

#pragma once

#include "Decls.h"

#ifndef DeclsEpsilon_H_
#define DeclsEpsilon_H_

class DeclsEpsilon : public Decls {
private:
  NodeType type;
public:
  DeclsEpsilon();
  void typeCheck();
  void makeCode();
};

#endif /* DeclsEpsilon_H_ */
