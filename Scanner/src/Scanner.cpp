/*
 * Scanner.cpp
 *
 *  Created on: Sep 26, 2012
 *      Author: knad0001
 */

#include "../includes/Scanner.h"
#include "../../Automat/includes/Automat.h"

Scanner::Scanner() {
	buffer = new Buffer("testinput");
	automat = new Automat();
	this->counter = 0;
}

Scanner::~Scanner() {
	// TODO Auto-generated destructor stub
}

// returns token
Token* Scanner::nextToken() {
	char c;
	do {
		// Lesen bis zum Lexem
		c = buffer->getChar();
		if (c != '\0') {
			counter++;
		}
		// nur so aus spaß
		cout << c;
	} while (automat->handle(c) != Automat::UNDEFINED);
	// Wir haben ein Lexem!
	if (counter == 0) {
		// nichts gelesen! Kein Token
		// TODO: NULL TOKEN
		return new Token(automat->gettype(), automat->getline(), automat->getcolumn(), automat->getvalue(), automat->getinformation());;
	}
	// TODO: if identifier ===> symboletable
	return new Token(automat->gettype(), automat->getline(), automat->getcolumn(), automat->getvalue(), automat->getinformation());
}
