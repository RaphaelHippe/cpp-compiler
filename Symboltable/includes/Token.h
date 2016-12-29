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
    Token(int type, int line, int column, Information* inf);
    Token(int type, int line, int column, int value);

    int getLine();
    int getColumn();
    int getType();
    int getValue();
    Information* getInformation();
    char* getTokenString();
    int getTokenTextLength();

    enum Type
    {
        SIGN = 0,
        INTEGER,
        IDENTIFIER,
        IF,
        WHILE
    };
};
