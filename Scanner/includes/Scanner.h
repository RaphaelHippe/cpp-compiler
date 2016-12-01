/*
 * Scanner.h
 *
 *  Created on: Sep 26, 2012
 *      Author: knad0001
 */

 #include "./../../Buffer/includes/Buffer.h"
 #include "./../../Automat/includes/Automat.h"
 // #include "./../../Symboltable/includes/Token.h"

#ifndef SCANNER_H_
#define SCANNER_H_

class Scanner {
private:
  int counter;
  Buffer* buffer;
  Automat* automat;
public:
	Scanner();
	virtual ~Scanner();
	// Token* nextToken();
	int nextToken();
};

#endif /* SCANNER_H_ */
