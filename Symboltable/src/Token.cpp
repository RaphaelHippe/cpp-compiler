#include "../includes/Token.h"

Token::Token(int type, int line, int column, long int value, Information* inf)
{
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

long int Token::getValue()
{
    return value;
}

Information* Token::getInformation()
{
    return information;
}
