/*
 * Scanner.cpp
 *
 *  Created on: Sep 26, 2012
 *      Author: knad0001
 */

#include "../includes/Scanner.h"
#include "../../Automat/includes/Automat.h"

Scanner::Scanner() {
	// TODO Auto-generated constructor stub
	// Automat* automat;
	// Buffer*  buffer;

}

Scanner::~Scanner() {
	// TODO Auto-generated destructor stub
}

void Scanner::nextToken(){
	char c;
	buffer = new Buffer("testinput");
	automat = new Automat();
	do {
		c = buffer.getChar();
		// nur so aus spaß
		cout << c;
	} while (automat.handle(c) != Automat::UNDEFINED)

}
