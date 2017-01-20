/*
 * Automat.h
 *
 *  Created on: Jan 20, 2017
 *      Author: Raphael Hippe
 */
#include "./../../Symboltable/includes/Token.h"
#include "./../../Scanner/includes/Scanner.h"

#include "Arr.h"
#include "ArrEpsilon.h"
#include "Decl.h"
#include "Decls.h"
#include "DeclsEpsilon.h"
#include "Exp.h"
#include "ExpII.h"
#include "ExpIIExp.h"
#include "ExpIIIndex.h"
#include "ExpIIInteger.h"
#include "ExpIINegative.h"
#include "ExpIINot.h"
#include "Index.h"
#include "IndexEpsilon.h"
#include "Op.h"
#include "OpExp.h"
#include "OpExpEpsilon.h"
#include "Prog.h"
#include "Statement.h"
#include "StatementAssign.h"
#include "StatementBracket.h"
#include "StatementIfElse.h"
#include "StatementRead.h"
#include "StatementWhile.h"
#include "StatementWrite.h"
#include "Statements.h"
#include "StatementsEpsilon.h"
#include "Parsetree.h"

#ifndef Parser_H_
#define Parser_H_

class Parser {
private:
  Token* token;
  Scanner* scanner;
  Arr* arr();
  Decl* decl();
  Decls* decls();
  Exp* exp();
  ExpII* expII();
  Index* index();
  Op* op();
  OpExp* opExp();
  Prog* prog();
  Statement* statement();
  Statements* statements();
  bool error;
  bool checkToken(int otherType);
public:
  Parser(char* argv, char* argv2);
  virtual ~Parser();
  void nextToken();
  int parse();
};

#endif /* Parser_H_ */
