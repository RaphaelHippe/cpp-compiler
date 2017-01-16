#include "../includes/Scanner.h"
#include "../../Automat/includes/Automat.h"
#include "../../Symboltable/includes/Information.h"
#include <cstring>
#include <iostream>
#include <sstream>

using namespace std;
Scanner::Scanner(char* argv, char* argv2) {

	if (argv == NULL) {
		argv = "../input/in.txt";
		argv2 = "../output/out.txt";
	} else if (argv2 == NULL) {
		argv2 = "out.txt";
	}

	// TODO: maybe a small check if argv and argv2 are actually ending in .txt or something?

 	buffer = new Buffer(argv);
	filedesc = open(argv2, O_WRONLY | O_CREAT|O_TRUNC, 0666);

	symTable = new Symboltable();
	symTable->initSymbols();
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
								case 8:
																translatedType = "MINUS          ";
																break;
								case 9:
																translatedType = "COLON          ";
																break;
								case 10:
																translatedType = "STAR           ";
																break;
								case 11:
																translatedType = "SMALLER        ";
																break;
								case 12:
																translatedType = "GREATER        ";
																break;
								case 13:
																translatedType = "EQUALS         ";
																break;
								case 14:
																translatedType = "ASSIGNMENT     ";
																break;
								case 15:
																translatedType = "WEIRDTHING     ";
																break;
								case 16:
																translatedType = "EXCLAMATION    ";
																break;
								case 17:
																translatedType = "ANDAND         ";
																break;
								case 18:
																translatedType = "SEMICOLON      ";
																break;
								case 19:
																translatedType = "STARTBRACKETA  ";
																break;
								case 20:
																translatedType = "ENDBRACKETA    ";
																break;
								case 21:
																translatedType = "STARTBRACKETB  ";
																break;
								case 22:
																translatedType = "ENDBRACKETB    ";
																break;
								case 23:
																translatedType = "STARTBRACKETC  ";
																break;
								case 24:
																translatedType = "ENDBRACKETC    ";
																break;
								}

								return translatedType;
}

// returns token
Token* Scanner::nextToken() {
// int Scanner::nextToken() {
								char c;
								int automat_result;
								Token* token;
								do {
																// Lesen bis zum Lexem
																c = buffer->getChar();
																if (c != '\0' && c != '\n' && c != ' ') {
																								counter++;
																}
																automat_result = automat->handle(c);
																// 0 -> checkLexem und Step Back
																// 20 -> checkLexem kein Step Back
																// -1 -> Error Token
																// -99 -> End of File
								} while (automat_result != 0 && automat_result != 20 && automat_result != -1 && automat_result != -99 && automat_result != 24);
								switch (automat_result) {
								case 24:
																// cout << "End of Comment \n";
																counter = 0;
																// token = new Token(1,1,1
																token = NULL;
																// token = new Token(automat->gettype(), automat->getline(), automat->getcolumn());
																// return 1;
																break;
								case 0:
																if (c == '\n' || c == ' ') {
																								counter++;
																}
																counter--;
																// automat->decreaseColumn();
																write(filedesc, "Token ", 6);
																write(filedesc, translateType(automat->gettype()), 15);
																write(filedesc, " Line: ", 7);
																writeInt(automat->getline(), filedesc);
																write(filedesc, " Column: ", 9);
																writeInt(automat->getcolumn() - counter, filedesc);
																buffer->stepBack(1);
																if (automat->gettype() == 1) {
																								// insert into sym table
																								buffer->stepBack(counter);
																								char word[counter + 1];
																								for (size_t i = 0; i < counter; i++) {
																																word[i] = buffer->getChar();
																								}
																								word[counter] = '\0';
																								Information* myInformation = new Information(word);
																								Key* myKey = symTable->insert(myInformation);
																								Information* test = symTable->lookup(myKey);
																								token = new Token(automat->gettype(), automat->getline(), automat->getcolumn() - counter, myInformation);
																								write(filedesc, " ", 1);
																								write(filedesc, word, counter);
																}

																if (automat->gettype() == 2) {
																								buffer->stepBack(counter);
																								char number[counter];
																								for (size_t i = 0; i < counter; i++) {
																																number[i] = buffer->getChar();
																								}
																								stringstream str(number);
																								int x;
																								str >> x;
																								if (!str) {
																																// The conversion failed.
																																cout << "conversion failed!! \n";
																																//  x = 0; ?
																																token = new Token(automat->gettype(), automat->getline(), automat->getcolumn() - counter, 0);

																								} else {
																																cout << "conversion should work!! \n";
																																token = new Token(automat->gettype(), automat->getline(), automat->getcolumn() - counter, x);
																								}
																								//  number[counter] = '\0';
																								// 1 3 2 4 5
																								write(filedesc, " ", 1);
																								write(filedesc, number, counter);
																}
																write(filedesc, "\n", 1);
																counter = 0;
																break;
								// return 1;
								case 20:
																// counter--;
																write(filedesc, "Token ", 6);
																write(filedesc, translateType(automat->gettype()), 15);
																write(filedesc, " Line: ", 7);
																writeInt(automat->getline(), filedesc);
																write(filedesc, " Column: ", 9);
																writeInt(automat->getcolumn() - counter, filedesc);
																write(filedesc, "\n", 1);
																counter = 0;
																// this is an error token so far - we need to figure out what the value / information is for a sign ;)
																// token = new Token(automat->gettype(), automat->getline(), automat->getcolumn() - counter);
																token = NULL;
																break;
								// return 1;
								case -1:
																cout << "Error-Token: Type: " << automat->gettype() << " Line: " << automat->getline() << " Column: " << automat->getcolumn() - counter << " Counter: " << counter << " raw column: " << automat->getcolumn() << c;
																cout << '\n';
																counter = 0;
																// token = new Token(automat->gettype(), automat->getline(), automat->getcolumn() - counter);
																token = NULL;
																break;
								// return 1;
								case -99:
																cout << "End of File. Exiting...";
																cout << '\n';
																token = NULL;
																break;
								// return 0;
								default:
																cout << "Unexpected Error. Exiting...";
																cout << '\n';
																token = NULL;
																// return 0;
								}
								return token;
}

Scanner::~Scanner() {
								// TODO Auto-generated destructor stub
								close(filedesc);
}
