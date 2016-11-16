/*
 * Automat.h
 *
 *  Created on: Jul 5, 2012
 *      Author: knad0001
 */
#pragma once
#include "State.h"
#include "./../../Symboltable/includes/Information.h"
#include "Initstate.h"

#ifndef Automat_H_
#define Automat_H_


class Automat {
private:
	State* _state;
public:
	Automat();
	virtual ~Automat();
	// void setState(State* state);
	int handle(char c);
	// int gettype();
	// int getline();
	// int getcolumn();
  // int getvalue();
	// Information* getinformation();
	// enum States {
	// 	INIT,
	// 	UNDEFINED
	// };
};

#endif /* Automat_H_ */
