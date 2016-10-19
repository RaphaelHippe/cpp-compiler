/*
 * Automat.h
 *
 *  Created on: Jul 5, 2012
 *      Author: knad0001
 */

#include "State.h"

#ifndef Automat_H_
#define Automat_H_


class Automat {
private:
	State* _state;
public:
	Automat();
	virtual ~Automat();
	void setState(State* state);
	int handle(char c);
	enum States {
		INIT,
		UNDEFINED
	};
};

#endif /* Automat_H_ */
