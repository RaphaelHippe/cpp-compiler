/*
 * Automat.h
 *
 *  Created on: Jul 5, 2012
 *      Author: knad0001
 */
#include "./../../Symboltable/includes/Information.h"
#include "Initstate.h"
#include "Identifierstate.h"
#include "Integerstate.h"
#include "Signstate.h"

#ifndef Automat_H_
#define Automat_H_


class Automat {
private:
	enum States {
		INIT,
		IDENTIFIER,
		INTEGER,
		SIGN,
		UNDEFINED
	};
	States _state;
	Initstate initstate;
	Identifierstate identifierstate;
	Integerstate integerstate;
	Signstate signstate;
public:
	Automat();
	virtual ~Automat();
	void setState(int stateresult);
	int handle(char c);
	// int gettype();
	// int getline();
	// int getcolumn();
  // int getvalue();
	// Information* getinformation();
};

#endif /* Automat_H_ */
