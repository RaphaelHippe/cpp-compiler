/*
 * Information.h
 *
 *  Created on: Jul 17, 2016
 *      Author: Raphael Hippe
 */

#include "../../Parser/includes/NodeTypes.h"
#include <string>

#ifndef Information_H_
#define Information_H_

class Information {
private:
  char lexem[1024];
  int myType;
  char* lexemPointer;
  char currentChar;
  NodeType type;
public:
	Information(char word[]);
	virtual ~Information();
  char* getLexemPointer();
  std::string getLexem();
  void incrementLexemPointer();
  int getType();
  bool compairLexem(char word[]);
  void setType(int type);
  int calcHashValue();
  void printLexem();
  void resetLexemPointer();

  NodeType getNodeType();
  void setNodeType(NodeType type);

};

#endif /* Information_H_ */
