/*
 * Information.h
 *
 *  Created on: Jul 17, 2016
 *      Author: Raphael Hippe
 */

#ifndef Information_H_
#define Information_H_


class Information {
private:
  char lexem[1024];
  int myType;
  char* lexemPointer;
  char currentChar;
public:
	Information(char word[]);
	virtual ~Information();
  char* getLexemPointer();
  void incrementLexemPointer();
  char getType();
  bool compairLexem(char word[]);
  void setType(int type);
  int calcHashValue();
  void printLexem();
  void resetLexemPointer();

};

#endif /* Information_H_ */
