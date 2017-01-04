/*
 * Symboltable.h
 *
 *  Created on: Sep 26, 2012
 *      Author: knad0001
 *  Edited:
 *      Author: Raphael Hippe
 */
 #include "../includes/List.h"
 #include "../includes/Key.h"
 #include "../includes/Information.h"

#ifndef SYMBOLTABLE_H_
#define SYMBOLTABLE_H_

#define TABLE_SIZE 1024

class Symboltable {
private:
	List *table;
	Key* myKey;
	int myHashValue;
	int factor;
	char currentChar;
	char currentLexem[];
public:
	Symboltable();
	virtual ~Symboltable();
	Key* insert(Information* value);
	Key* testInsert(Information* value, int testHashValue);
	Information* lookup(Key* key);
  void initSymbols();
};

#endif /* SYMBOLTABLE_H_ */
