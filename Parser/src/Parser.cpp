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

Parsetree* Parser::parse(){
        nextToken();
        Prog* myProg = prog();
        if (token != NULL) {
                syntaxError();
        }
        if (error) {
                delete myProg;
                return NULL;
        }
        return new Parsetree(myProg);
}

Arr* Parser::arr(){
        if (checkToken(Token::SQUAREBRACKETOPEN)) {
                nextToken();
                Arr* myArr = new Arr();
                if (checkToken(Token::INTEGER)) {
                        if (error) {
                                return myArr;
                        }
                        myArr->addNode(new IntegerN(token));
                        nextToken();
                } else {
                        syntaxError();
                }
                if (!checkToken(Token::SQUAREBRACKETCLOSE)) {
                        syntaxError();
                }
                nextToken();
                return myArr;
        } else {
                // Epsilon
                return new ArrEpsilon();
        }
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
                nextToken();
        } else {
                syntaxError();
        }
        return myDecl;
}

Decls* Parser::decls(){
        if (checkToken(Token::INT)) {
                nextToken();
                Decls* myDecls = new Decls();
                if (error) {
                        return myDecls;
                }
                myDecls->addNode(decl());
                if (checkToken(Token::SEMICOLON)) {
                        nextToken();
                        if (error) {
                                return myDecls;
                        }
                        myDecls->addNode(decls());
                } else {
                        syntaxError();
                }
                return myDecls;
        } else {
                return new DeclsEpsilon();
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
                syntaxError();
        }
        return NULL;
}

ExpII* Parser::expII(){
        if (checkToken(Token::BRACKETOPEN)) {
                ExpIIExp* myExpII = new ExpIIExp();
                nextToken();
                if (error) {
                        return myExpII;
                }
                myExpII->addNode(exp());
                if (!checkToken(Token::BRACKETCLOSE)) {
                        syntaxError();
                } else{
                        nextToken();

                }
                return myExpII;
        } else if(checkToken(Token::IDENTIFIER)) {
                ExpIIIndex* myExpII = new ExpIIIndex();
                myExpII->addNode(new Identifier(token));
                nextToken();
                if (error) {
                        return myExpII;
                }
                myExpII->addNode(index());
                return myExpII;
        } else if(checkToken(Token::INTEGER)) {
                ExpIIInteger* myExpII = new ExpIIInteger();
                myExpII->addNode(new IntegerN(token));
                nextToken();
                if (error) {
                        return myExpII;
                }
                return myExpII;
        } else if(checkToken(Token::MINUS)) {
                ExpIINegative* myExpII = new ExpIINegative();
                nextToken();
                if (error) {
                        return myExpII;
                }
                myExpII->addNode(expII());
                return myExpII;
        } else if(checkToken(Token::EXMARK)) {
                ExpIINot* myExpII = new ExpIINot();
                nextToken();
                if (error) {
                        return myExpII;
                }
                myExpII->addNode(expII());
                return myExpII;
        } else {
                // Syntax error - not reachable ?!
                syntaxError();
                return NULL;
        }
}

Index* Parser::index(){
        if (checkToken(Token::SQUAREBRACKETOPEN)) {
          nextToken();
                Index* myIndex = new Index();
                myIndex->addNode(exp());
                if (!checkToken(Token::SQUAREBRACKETCLOSE)) {
                        syntaxError();
                } else {
                  nextToken();

                }
                return myIndex;
        } else {
                // Epsilon
                return new IndexEpsilon();
        }
}

Op* Parser::op(){
        Op* myOp = new Op(token);
        nextToken();
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
                return new OpExpEpsilon();
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
                nextToken();
                if (error) {
                        return myStatement;
                }
                myStatement->addNode(index());
                if (checkToken(Token::ASSIGNMENT)) {
                        nextToken();
                        if (error) {
                                return myStatement;
                        }
                        myStatement->addNode(exp());
                } else {
                        syntaxError();
                }
                return myStatement;
        } else if (checkToken(Token::WRITE)) {
                StatementWrite* myStatement = new StatementWrite();
                nextToken();
                if (checkToken(Token::BRACKETOPEN)) {
                        nextToken();
                        if (error) {
                                return myStatement;
                        }
                        myStatement->addNode(exp());
                        if (!checkToken(Token::BRACKETCLOSE)) {
                                syntaxError();
                        } else {
                                nextToken();

                        }
                } else {
                        syntaxError();
                }
                return myStatement;
        } else if (checkToken(Token::READ)) {
                StatementRead* myStatement = new StatementRead();
                nextToken();
                if (checkToken(Token::BRACKETOPEN)) {
                        nextToken();
                        if (checkToken(Token::IDENTIFIER)) {
                                myStatement->addNode(new Identifier(token));
                                nextToken();
                        } else {
                                syntaxError();
                        }
                        if (error) {
                                return myStatement;
                        }
                        myStatement->addNode(index());
                        if (!checkToken(Token::BRACKETCLOSE)) {
                                syntaxError();
                        } else {
                                nextToken();

                        }
                } else {
                        syntaxError();
                }
                return myStatement;
        } else if (checkToken(Token::CURLYBRACKETOPEN)) {
                StatementBracket* myStatement = new StatementBracket();
                nextToken();
                if (error) {
                        return myStatement;
                }
                myStatement->addNode(statements());
                if (!checkToken(Token::CURLYBRACKETCLOSE)) {
                        syntaxError();
                } else {
                        nextToken();

                }
                return myStatement;
        } else if (checkToken(Token::IF)) {
                StatementIfElse* myStatement = new StatementIfElse();
                nextToken();
                if (checkToken(Token::BRACKETOPEN)) {
                        nextToken();
                        if (error) {
                                return myStatement;
                        }
                        myStatement->addNode(exp());
                } else {
                        syntaxError();
                }
                if (checkToken(Token::BRACKETCLOSE)) {
                        nextToken();
                        if (error) {
                                return myStatement;
                        }
                        myStatement->addNode(statement());
                } else {
                        syntaxError();
                }
                if (checkToken(Token::ELSE)) {
                        nextToken();
                        if (error) {
                                return myStatement;
                        }
                        myStatement->addNode(statement());
                } else {
                        syntaxError();
                }
                return myStatement;
        } else if (checkToken(Token::WHILE)) {
                StatementWhile* myStatement = new StatementWhile();
                nextToken();
                if (checkToken(Token::BRACKETOPEN)) {
                        nextToken();
                        if (error) {
                                return myStatement;
                        }
                        myStatement->addNode(exp());
                } else {
                        syntaxError();
                }
                if (checkToken(Token::BRACKETCLOSE)) {
                        nextToken();
                        if (error) {
                                return myStatement;
                        }
                        myStatement->addNode(statement());
                } else {
                        syntaxError();
                }
                return myStatement;
        } else {
                syntaxError();
                return NULL;
        }
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
                        nextToken();
                        if (error) {
                                return myStatements;
                        }
                        myStatements->addNode(statements());
                } else {
                        syntaxError();
                }
                return myStatements;
        } else {
                // Epsilon
                return new StatementsEpsilon();
        }
}

bool Parser::checkToken(int otherType){
        return (token != NULL && token->getType() == otherType);
}

void Parser::syntaxError(){
        if (token != NULL && !error) {
                cerr << "Syntax-Error: Line: " << token->getLine() << " Column: " << token->getColumn() << " Token Name\n";
        } else if (!error) {
          cerr << "Syntax Error: Unknown token detected. \n";
        }
        error = true;
}

Parser::~Parser() {
}
