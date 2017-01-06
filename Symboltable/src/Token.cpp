#include "../includes/Token.h"
#include <iostream>
#include <string.h>

using namespace std;

Token::Token(int type, int line, int column, Information* inf)
{
        // TODO: implement error type
        this->type = type;
        this->line = line;
        this->column = column;
        this->value = 0;
        this->information = inf;
}
Token::Token(int type, int line, int column, int value)
{
        // TODO: implement error type
        this->type = type;
        this->line = line;
        this->column = column;
        this->value = value;
        this->information = NULL;
}
Token::Token(int type, int line, int column)
{
        // error token
        this->type = type;
        this->line = line;
        this->column = column;
        this->value = NULL;
        this->information = NULL;
}

int Token::getLine()
{
        return line;
}

int Token::getColumn()
{
        return column;
}

int Token::getType()
{
        return type;
}

int Token::getValue()
{
        return value;
}

Information* Token::getInformation()
{
        return information;
}

char* Token::getTokenString(){
        test = "lul";
        test2 = "Token xyzss";
        tokenText = strcat(test2, test);
        return tokenText;
}

int Token::getTokenTextLength(){
        tokenText += '\0';
        char* pointer = tokenText;
        int tokenTextLength = 0;

        while (pointer != '\0') {
                tokenTextLength++;
                cout << "lul" << '\n';
                cout << pointer << '\n';
                pointer++;
        }
        return tokenTextLength;
}


// TODO: implement a getString method
// Token identifier Line: x Column: y Lexem z
// Token Integer Line: x Column: y value z
