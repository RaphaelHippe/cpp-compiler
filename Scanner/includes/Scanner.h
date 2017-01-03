 #include "./../../Buffer/includes/Buffer.h"
 #include "./../../Automat/includes/Automat.h"
 #include "./../../Symboltable/includes/Token.h"
 #include "./../../Symboltable/includes/Information.h"
 #include "./../../Symboltable/includes/Symboltable.h"

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
  Symboltable* symTable;
  char* translatedType;
  int filedesc;
  char* translateType(int type);
public:
	Scanner(char* argv, char* argv2);
  Scanner();
	virtual ~Scanner();
	// Token* nextToken();
	int nextToken();
  void writeInt(long int value, int filedesc);
};

#endif /* SCANNER_H_ */
