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
}

Scanner::~Scanner() {
	// TODO Auto-generated destructor stub
}

// returns token
Token* Scanner::nextToken(){
	char c;
	char token;
	char lexem;
	do {
		// Lesen bis zum Lexem
		c = buffer.getChar();
		// nur so aus spaß
		cout << c;
	} while (automat.handle(c) != Automat::UNDEFINED)
	// Wir haben ein Lexem!
	lexem = automat.getLexem();
	if (lexem.length == 0) {
		// lexem is empty -> no token
	}

}
