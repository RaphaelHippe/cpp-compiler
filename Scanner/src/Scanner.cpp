/*
 * Scanner.cpp
 *
 *  Created on: Sep 26, 2012
 *      Author: knad0001
 */

#include "../includes/Scanner.h"
#include "../../Automat/includes/Automat.h"
#include <iostream>

using namespace std;
Scanner::Scanner() {
	// buffer = new Buffer("../tests/testinput");
	buffer = new Buffer("../tests/tryit.txt");
	automat = new Automat();
	this->counter = 1;
}

Scanner::~Scanner() {
	// TODO Auto-generated destructor stub
}

// returns token
// Token* Scanner::nextToken() {
int Scanner::nextToken() {
	char c;
	int automat_result;
	// Token* t;
	do {
		// Lesen bis zum Lexem
		c = buffer->getChar();
		if (c != '\0' && c != '\n') {
			// TODO: is this correct?
			counter++;
		}
		automat_result = automat->handle(c);
		// if (automat_result != 0 && automat_result != 20 &&
		// 		automat_result != -99 && automat_result != -1) {
		// 	// TODO: Check if this is a better approach
		// 	counter++;
		// }

		// cout << c;
		// cout << " - automat_result: " << automat_result << " Automat State: " << automat->gettype();
		// cout << '\n';

		// 0 -> checkLexem und Step Back
		// 20 -> checkLexem kein Step Back
		// -1 -> Error Token
		// -99 -> End of File
	} while (automat_result != 0 && automat_result != 20 && automat_result != -1 && automat_result != -99);
	// Wir haben ein Lexem!
	// if (counter == 0) {
		// cout << "Counter is 0";
		// nichts gelesen! Kein Token
		// TODO: if identifier ===> symboletable
		// // TODO: NULL TOKEN
		// t = new Token(automat->gettype(), automat->getline(), automat->getcolumn(), automat->getvalue(), automat->getinformation());;
		// return t;
	// } else {
		switch (automat_result) {
			case 0:
				counter--;
				cout << "Token: Type: " << automat->gettype() << " Line: " << automat->getline() << " Column: " << automat->getcolumn() - counter << " Counter: " << counter << " raw column: " << automat->getcolumn();
				cout << '\n';
				// automat->checkLexem("test");
				buffer->stepBack(1);
				automat->decreaseColumn();
				counter = 0;
				return 1;
			case 20:
				cout << "Token: Type: " << automat->gettype() << " Line: " << automat->getline() << " Column: " << automat->getcolumn() - counter << " Counter: " << counter << " raw column: " << automat->getcolumn();
				cout << '\n';
				// automat->checkLexem("test");
				counter = 0;
				return 1;
			case -1:
				cout << "Error-Token: Type: " << automat->gettype() << " Line: " << automat->getline() << " Column: " << automat->getcolumn() - counter << " Counter: " << counter << " raw column: " << automat->getcolumn();
				cout << '\n';
				// automat->checkLexem("test");
				counter = 0;
				return 1;
			case -99:
				cout << "End of File. Exiting...";
				cout << '\n';
				return 0;
			default:
				cout << "Unexpected Error. Exiting...";
				return 0;
		}
	// }
	// t = new Token(automat->gettype(), automat->getline(), automat->getcolumn(), automat->getvalue(), automat->getinformation());;
	// return t;
}
