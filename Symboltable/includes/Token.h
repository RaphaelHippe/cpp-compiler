#pragma once

#include "Information.h"
#include <iostream>

using namespace std;

class Token {
private:
int line;
int column;
int type;
long value;
Information* information;
char* test;
char* test2;
char* tokenText;


public:
Token(int type, int line, int column);
Token(int type, int line, int column, Information* inf);
Token(int type, int line, int column, int value);

int getLine();
int getColumn();
int getType();
int getValue();
std::string getLexem();
Information* getInformation();
char* getTokenString();
int getTokenTextLength();

enum Type
{
        SIGN = 0,
        INTEGER,
        IDENTIFIER,
        IF,
        WHILE,
        ELSE,
        WRITE,
        READ,
        INT,
        PLUS,
        MINUS,
        STAR,
        COLON,
        SMALLER,
        GREATER,
        EQUALS,
        ASSIGNMENT,
        WEIRDTHING,
        EXMARK,
        ANDAND,
        SEMICOLON,
        BRACKETOPEN,
        BRACKETCLOSE,
        CURLYBRACKETOPEN,
        CURLYBRACKETCLOSE,
        SQUAREBRACKETOPEN,
        SQUAREBRACKETCLOSE,
        ERROR
};
};
