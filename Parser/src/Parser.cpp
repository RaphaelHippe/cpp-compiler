#include "../includes/Parser.h"
#include "../../Scanner/includes/Scanner.h"
#include <iostream>

using namespace std;
Parser::Parser(char* argv, char* argv2){
        scanner = new Scanner(argv, argv2);
}

void Parser::nextToken(){
        token = scanner->nextToken();
}

int Parser::parse(){
        nextToken();
        if (token == NULL) {
                return 0;
        } else {
                return 1;
        }
}

Arr* Parser::arr(){
        if (checkToken(Token::SQUAREBRACKETOPEN)) {
                Arr* myArr = new Arr();
                if (checkToken(Token::INTEGER)) {
                        if (error) {
                                return myArr;
                        }
                        myArr->addNode(new IntegerN(token));
                } else {
                        // Syntax Error
                }
                if (!checkToken(Token::SQUAREBRACKETCLOSE)) {
                        // Syntax Error
                }
                return myArr;
        } else {
                // Epsilon
        }
        return NULL;
}

Decl* Parser::decl(){
        Decl* myDecl = new Decl();
        if (error) {
                return myDecl;
        }
        myDecl->addNode(arr());
        if (checkToken(Token::IDENTIFIER)) {
                if (error) {
                        return myDecl;
                }
                myDecl->addNode(new Identifier(token));
        } else {
                // Syntax Error
        }
        return myDecl;
}

Decls* Parser::decls(){
        if (checkToken(Token::INT)) {
                Decls* myDecls = new Decls();
                if (error) {
                        return myDecls;
                }
                myDecls->addNode(decl());
                if (checkToken(Token::SEMICOLON)) {
                        if (error) {
                                return myDecls;
                        }
                        myDecls->addNode(decls());
                } else {
                        // Syntax Error
                }
                return myDecls;
        } else {
                // Epsilon Node (Extra Klasse ?!)
                return new Decls();
        }
}

Exp* Parser::exp(){
        if (checkToken(Token::BRACKETOPEN) || checkToken(Token::IDENTIFIER) ||
            checkToken(Token::INTEGER) || checkToken(Token::MINUS) ||
            checkToken(Token::EXMARK)) {
                Exp* myExp = new Exp();
                if (error) {
                        return myExp;
                }
                myExp->addNode(expII());
                if (error) {
                        return myExp;
                }
                myExp->addNode(opExp());
                return myExp;
        } else {
                // syntax error
        }
        return NULL;
}

ExpII* Parser::expII(){
        if (checkToken(Token::BRACKETOPEN)) {
                ExpIIExp* myExpII = new ExpIIExp();
                if (error) {
                        return myExpII;
                }
                myExpII->addNode(exp());
                if (!checkToken(Token::BRACKETCLOSE)) {
                        // Syntax Error
                }
                return myExpII;
        } else if(checkToken(Token::IDENTIFIER)) {
                ExpIIIndex* myExpII = new ExpIIIndex();
                myExpII->addNode(new Identifier(token));
                if (error) {
                  return myExpII;
                }
                myExpII->addNode(index());
                return myExpII;
        } else if(checkToken(Token::INTEGER)) {
                ExpIIInteger* myExpII = new ExpIIInteger();
                myExpII->addNode(new IntegerN(token));
                if (error) {
                  return myExpII;
                }
                return myExpII;
        } else if(checkToken(Token::MINUS)) {
                ExpIINegative* myExpII = new ExpIINegative();
                if (error) {
                  return myExpII;
                }
                myExpII->addNode(expII());
                return myExpII;
        } else if(checkToken(Token::EXMARK)) {
                ExpIINot* myExpII = new ExpIINot();
                if (error) {
                  return myExpII;
                }
                myExpII->addNode(expII());
                return myExpII;
        } else {
                // Syntax error - not reachable ?!
        }
        return NULL;
}

Index* Parser::index(){
        if (checkToken(Token::SQUAREBRACKETOPEN)) {
                Index* myIndex = new Index();
                myIndex->addNode(exp());
                if (!checkToken(Token::SQUAREBRACKETCLOSE)) {
                  // Syntax Error
                }
                return myIndex;
        } else {
                // Epsilon
        }
}

Op* Parser::op(){
    Op* myOp = new Op(token);
    return myOp;
}

OpExp* Parser::opExp(){
        if (checkToken(Token::PLUS) || checkToken(Token::MINUS) ||
            checkToken(Token::STAR) || checkToken(Token::COLON) ||
            checkToken(Token::SMALLER) || checkToken(Token::GREATER) ||
            checkToken(Token::EQUALS) || checkToken(Token::WEIRDTHING) ||
            checkToken(Token::ANDAND)) {
                OpExp* myOpExp = new OpExp();
                if (error) {
                  return myOpExp;
                }
                myOpExp->addNode(op());
                if (error) {
                  return myOpExp;
                }
                myOpExp->addNode(exp());
                return myOpExp;
        } else {
                // Epsilon
        }
        return NULL;
}

Prog* Parser::prog(){
        Prog* myProg = new Prog();
        myProg->addNode(decls());

        if (!error) {
                myProg->addNode(statements());
        }
        return myProg;
}

Statement* Parser::statement(){
        if (checkToken(Token::IDENTIFIER)) {
                StatementAssign* myStatement = new StatementAssign();
                myStatement->addNode(new Identifier(token));
                if (error) {
                        return myStatement;
                }
                myStatement->addNode(index());
                if (checkToken(Token::ASSIGNMENT)) {
                        if (error) {
                                return myStatement;
                        }
                        myStatement->addNode(exp());
                } else {
                        // Syntax Error
                }
                return myStatement;
        } else if (checkToken(Token::WRITE)) {
                StatementWrite* myStatement = new StatementWrite();
                if (checkToken(Token::BRACKETOPEN)) {
                        if (error) {
                                return myStatement;
                        }
                        myStatement->addNode(exp());
                        if (!checkToken(Token::BRACKETCLOSE)) {
                                // Syntax Error
                        }
                } else {
                        // Syntax Error
                }
                return myStatement;
        } else if (checkToken(Token::READ)) {
                StatementRead* myStatement = new StatementRead();
                if (checkToken(Token::BRACKETOPEN)) {
                        if (checkToken(Token::IDENTIFIER)) {
                                myStatement->addNode(new Identifier(token));
                        } else {
                                // Syntax Error
                        }
                        if (error) {
                                return myStatement;
                        }
                        myStatement->addNode(index());
                        if (!checkToken(Token::BRACKETCLOSE)) {
                                // Syntax Error
                        }
                } else {
                        // Syntax Error
                }
                return myStatement;
        } else if (checkToken(Token::CURLYBRACKETOPEN)) {
                StatementBracket* myStatement = new StatementBracket();
                if (error) {
                        return myStatement;
                }
                myStatement->addNode(statements());
                if (!checkToken(Token::CURLYBRACKETCLOSE)) {
                        // Syntax Error
                }
                return myStatement;
        } else if (checkToken(Token::IF)) {
                StatementIfElse* myStatement = new StatementIfElse();
                if (checkToken(Token::BRACKETOPEN)) {
                        if (error) {
                                return myStatement;
                        }
                        myStatement->addNode(exp());
                } else {
                        // Syntax Error
                }
                if (checkToken(Token::BRACKETCLOSE)) {
                        if (error) {
                                return myStatement;
                        }
                        myStatement->addNode(statement());
                } else {
                        // Syntax Error
                }
                if (checkToken(Token::ELSE)) {
                        if (error) {
                                return myStatement;
                        }
                        myStatement->addNode(statement());
                } else {
                        // Syntax Error
                }
                return myStatement;
        } else if (checkToken(Token::WHILE)) {
                StatementWhile* myStatement = new StatementWhile();
                if (checkToken(Token::BRACKETOPEN)) {
                        if (error) {
                                return myStatement;
                        }
                        myStatement->addNode(exp());
                } else {
                        // Syntax Error
                }
                if (checkToken(Token::BRACKETCLOSE)) {
                        if (error) {
                                return myStatement;
                        }
                        myStatement->addNode(statement());
                } else {
                        // Syntax Error
                }
                return myStatement;
        } else {
                // Syntax Error
        }
        return NULL;
}

Statements* Parser::statements(){
        if (checkToken(Token::IDENTIFIER) || checkToken(Token::WRITE) ||
            checkToken(Token::READ) || checkToken(Token::CURLYBRACKETOPEN) ||
            checkToken(Token::IF) || checkToken(Token::WHILE)) {
                Statements* myStatements = new Statements();
                if (error) {
                        return myStatements;
                }
                myStatements->addNode(statement());
                if (checkToken(Token::SEMICOLON)) {
                        if (error) {
                                return myStatements;
                        }
                        myStatements->addNode(statements());
                } else {
                        // Syntax Error
                }
                return myStatements;
        } else {
                // Epsilon
        }
}

bool Parser::checkToken(int otherType){
        return (token != NULL && token->getType() == otherType);
}

Parser::~Parser() {
}
