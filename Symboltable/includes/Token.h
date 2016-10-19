#pragma once

#include "Information.h"

class Token
{
private:
    int line;
    int column;
    int type;
    long value;
    Information* information;

public:
    Token(int, int, int, long int, Information*);

    int getLine();
    int getColumn();
    int getType();
    long int getValue();
    Information* getInformation();
    std::string getTokenName(int);

    enum Type
    {
        SIGN = 0,
        INTEGER,
        IDENTIFIER,
        IF,
        WHILE
    };
};
