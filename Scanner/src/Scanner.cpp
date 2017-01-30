#include "../includes/Scanner.h"
#include "../../Automat/includes/Automat.h"
#include "../../Symboltable/includes/Information.h"
#include <error.h>
#include <errno.h>

Scanner::Scanner(char* argv, char* argv2) {

	if (argv == NULL) {
		argv = "../input/in.txt";
		argv2 = "../output/out.txt";
	} else if (argv2 == NULL) {
		argv2 = "out.txt";
	}

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
								case 1:
																translatedType = "Identifier     ";
																break;
								case 2:
																translatedType = "Integer        ";
																break;
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

Token* Scanner::nextToken() {

char c;
int automat_result;
Token* token;

	do {
		c = buffer->getChar();
		automat_result = automat->handle(c);

		if (c != '\0' && c != '\n' && c != ' ') {
			counter++;
		}

		if (automat_result == 24) {
			counter = 0;
		}

	} while (automat_result != 0 && automat_result != 20 && automat_result != -1 && automat_result != -99);

switch (automat_result) {

case 0: {

if (c != '\n' && c != ' ') {
	counter--;
}

write(filedesc, "Token ", 6);
write(filedesc, translateType(automat->gettype()), 15);
write(filedesc, " Line: ", 7);
writeInt(automat->getline(), filedesc);
write(filedesc, " Column: ", 9);
writeInt(automat->getcolumn() - counter, filedesc);
buffer->stepBack(1);
// Integer
if (automat->gettype() == 2) {

	buffer->stepBack(counter);
	char number[counter];

	for (size_t i = 0; i < counter; i++) {
		number[i] = buffer->getChar();
	}

long value = strtol(number, NULL, 10);

if (errno == ERANGE) {
	error(0, ERANGE, "LINE: %d Column: %d", automat->getline(), automat->getcolumn() - counter);
	errno = 0;
	token = new Token(Token::ERROR, automat->getline(), automat->getcolumn() - counter);
}

token = new Token(Token::INTEGER, automat->getline(), automat->getcolumn() - counter, value);
write(filedesc, " ", 1);
write(filedesc, number, counter);

}else{
// Alles neben Integer
	buffer->stepBack(counter);
	char word[counter + 1];

	for (size_t i = 0; i < counter; i++) {
		word[i] = buffer->getChar();
	}

	word[counter] = '\0';
	Information* myInformation = new Information(word);
	// Identifier => in Symboltabelle eintragen
	if (automat->gettype() == 1) {
		myInformation->setType(Token::IDENTIFIER);
	}

	Key* myKey = symTable->insert(myInformation);
	Information* info = symTable->lookup(myKey);
	// Get Token Type from symTable --> information
	token = new Token(info->getType(), automat->getline(), automat->getcolumn() - counter, info);
	write(filedesc, " ", 1);
	write(filedesc, word, counter);
}

write(filedesc, "\n", 1);
counter = 0;

}
break;
								case 20: {
																// write chars into token....
																buffer->stepBack(counter);
																char word[counter + 1];
																for (size_t i = 0; i < counter; i++) {
																        word[i] = buffer->getChar();
																}
																word[counter] = '\0';
																Information* myInformation = new Information(word);
																Key* myKey = symTable->insert(myInformation);
																Information* info = symTable->lookup(myKey);
																token = new Token(info->getType(), automat->getline(), automat->getcolumn() - counter, info);
																write(filedesc, "Token ", 6);
																write(filedesc, translateType(automat->gettype()), 15);
																write(filedesc, " Line: ", 7);
																writeInt(automat->getline(), filedesc);
																write(filedesc, " Column: ", 9);
																writeInt(automat->getcolumn() - counter, filedesc);
																write(filedesc, "\n", 1);
																counter = 0;
								}
								break;
								case -1: {
																fprintf(stderr, "Error: Type: %d Line: %d Column: %d \n", automat->gettype(), automat->getline(), automat->getcolumn() - counter);
																// write error lexem into token
																buffer->stepBack(counter);
																char word[counter + 1];
																for (size_t i = 0; i < counter; i++) {
																								word[i] = buffer->getChar();
																}
																word[counter] = '\0';
																Information* myInformation = new Information(word);
																token = new Token(Token::ERROR, automat->getline(), automat->getcolumn() - counter, myInformation);
																counter = 0;
								}
								break;
								case -99: {
																cout << "End of Party. Good Night, sleep well ;)";
																cout << '\n';
																token = NULL;
								}
								break;
								default: {
																cout << "Unexpected Error. Exiting...";
																cout << '\n';
																token = NULL;
								}
								}
								return token;
}

Scanner::~Scanner() {
								// TODO Auto-generated destructor stub
								close(filedesc);
}
