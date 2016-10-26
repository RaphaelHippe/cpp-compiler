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

public:
    Token(int, int, int, int, Information*);

    int getLine();
    int getColumn();
    int getType();
    int getValue();
    Information* getInformation();
    string getTokenString();

    enum Type
    {
        SIGN = 0,
        INTEGER,
        IDENTIFIER,
        IF,
        WHILE
    };
};
