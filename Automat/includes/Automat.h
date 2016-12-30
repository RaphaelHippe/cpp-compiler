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
		UNDEFINED,
		DEFINED,
		NEWLINE,
		PLUS,
		MINUS,
		COLON,
		STAR,
		SMALLER,
		GREATER,
		EQUALS,
		ASSIGNMENT,
		WEIRDTHING,
		EXCLAMATION,
		ANDAND,
		SEMICOLON,
		STARTBRACKETA,
		ENDBRACKETA,
		STARTBRACKETB,
		ENDBRACKETB,
		STARTBRACKETC,
		ENDBRACKETC
	};
	States _state;
	States _tokenState;
	Initstate initstate;
	Identifierstate identifierstate;
	Integerstate integerstate;
	Signstate signstate;
	int _column;
	int _line;
public:
	Automat();
	virtual ~Automat();
	void setState(int stateresult);
	int handle(char c);
	int checkLexem(char s[]);
	int gettype();
	int getline();
	int getcolumn();
	void decreaseColumn();
};

#endif /* Automat_H_ */
