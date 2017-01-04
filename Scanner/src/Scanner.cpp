#include "../includes/Scanner.h"
#include "../../Automat/includes/Automat.h"
#include "../../Symboltable/includes/Information.h"
#include <cstring>
#include <iostream>

using namespace std;
Scanner::Scanner(char* argv, char* argv2) {

	if (argv == NULL) {
		argv = "../tests/tryit.txt";
		argv2 = "out.txt";
	} else if (argv2 == NULL) {
		argv2 = "out.txt";
	}

	buffer = new Buffer(argv);
	filedesc = open(argv2, O_WRONLY | O_CREAT|O_TRUNC, 0666);

	symTable = new Symboltable();
	automat = new Automat();
	this->counter = 0;
}

void Scanner::writeInt(long int value, int filedesc){
	char intString[10000];
	int j = 0;
	sprintf(intString, "%ld", value);
	char * pointer = intString;
	while ( *(pointer+j) != '\0') {
		write(filedesc, pointer+j, 1);
		j++;
	}
}

char* Scanner::translateType(int type){

	switch (type) {
		// 1 === Identifier
		case 1:
			translatedType = "Identifier     ";
			break;
		// 2 === Integer
		case 2:
			translatedType = "Integer        ";
			break;
		// 3 === Sign
		case 7:
			translatedType = "PLUS           ";
			break;
		case 14:
			translatedType = "ASSIGNMENT     ";
			break;
		case 15:
			translatedType = "WEIRDTHING     ";
			break;
		case 17:
			translatedType = "ANDAND         ";
			break;
	}

	return translatedType;
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
		if (c != '\0' && c != '\n' && c != ' ') {
		// if (c != '\0') {
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
	} while (automat_result != 0 && automat_result != 20 && automat_result != -1 && automat_result != -99 && automat_result != 24);
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
			case 24:
				// cout << "End of Comment \n";
				counter = 0;
				return 1;
				break;
			case 0:
				if (c == '\n' || c == ' ') {
					counter++;
				}
				counter--;
				// automat->decreaseColumn();
				cout << "Token(0): Type: " << automat->gettype() << " Line: " << automat->getline() << " Column: " << automat->getcolumn() - counter << " Counter: " << counter << " raw column: " << automat->getcolumn();
				cout << translateType(automat->gettype());
				cout << '\n';
				write(filedesc, "Token ", 6);
				write(filedesc, translateType(automat->gettype()), 15);
				write(filedesc, " Line: ", 7);
				writeInt(automat->getline(), filedesc);
				write(filedesc, " Column: ", 9);
				writeInt(automat->getcolumn() - counter, filedesc);
				write(filedesc, "\n", 1);

				buffer->stepBack(1);

				if (automat->gettype() == 1) {
					// insert into sym table
					buffer->stepBack(counter);
					char word[counter + 1];
					for (size_t i = 0; i < counter; i++) {
						word[i] = buffer->getChar();
					}
						word[counter] = '\0';
					//  myInformation = new Information(word);
					Information* myInformation = new Information(word);
					// myInformation->printLexem();
					Key* myKey = symTable->insert(myInformation);
					Information* test = symTable->lookup(myKey);
					// test->printLexem();
					// cout << "symTable " << symTable->lookup(myKey);
					// Token* token = new Token(int type, int line, int column, int value, Information* inf);
					Token* token = new Token(automat->gettype(), automat->getline(), automat->getcolumn() - counter, myInformation);
					// cout << token->getLine() << " Token Line \n";
					// cout << token->getTokenTextLength() << "\n";
					// write(filedesc, token->getTokenString(), 9);
				}

				// automat->checkLexem("test");
				counter = 0;
				return 1;
			case 20:
				// counter--;
				cout << "Token(20): Type: " << automat->gettype() << " Line: " << automat->getline() << " Column: " << automat->getcolumn() - counter << " Counter: " << counter << " raw column: " << automat->getcolumn();
				cout << '\n';
				write(filedesc, "Token ", 6);
				write(filedesc, translateType(automat->gettype()), 15);
				write(filedesc, " Line: ", 7);
				writeInt(automat->getline(), filedesc);
				write(filedesc, " Column: ", 9);
				writeInt(automat->getcolumn() - counter, filedesc);
				write(filedesc, "\n", 1);
				counter = 0;
				return 1;
			case -1:
				cout << "Error-Token: Type: " << automat->gettype() << " Line: " << automat->getline() << " Column: " << automat->getcolumn() - counter << " Counter: " << counter << " raw column: " << automat->getcolumn() << c;
				cout << '\n';
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
			// write(filedesc, token.)
	// return t;
}

Scanner::~Scanner() {
	// TODO Auto-generated destructor stub
	close(filedesc);
}
