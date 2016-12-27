/*
 * Scanner.h
 *
 *  Created on: Sep 26, 2012
 *      Author: knad0001
 */

 #include "./../../Buffer/includes/Buffer.h"
 #include "./../../Automat/includes/Automat.h"
 // #include "./../../Symboltable/includes/Token.h"
 #include "./../../Symboltable/includes/Information.h"

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#ifndef SCANNER_H_
#define SCANNER_H_

class Scanner {
private:
  int counter;
  Buffer* buffer;
  Automat* automat;
  int filedesc;
public:
	Scanner();
	virtual ~Scanner();
	// Token* nextToken();
	int nextToken();
  void writeInt(long int value, int filedesc);
};

#endif /* SCANNER_H_ */
