#include "../includes/Token.h"
#include <iostream>

using namespace std;

Token::Token(int type, int line, int column, int value, Information* inf)
{
    // TODO: implement error type
    this->type = type;
    this->line = line;
    this->column = column;
    this->value = value;
    this->information = inf;
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
// 
// std::string Token::getTokenString(){
//   return "Token xyz";
// }

// TODO: implement a getString method
// Token identifier Line: x Column: y Lexem z
// Token Integer Line: x Column: y value z
