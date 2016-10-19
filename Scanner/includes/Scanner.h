/*
 * Scanner.h
 *
 *  Created on: Sep 26, 2012
 *      Author: knad0001
 */

 #include "./../../Buffer/includes/Buffer.h"

#ifndef SCANNER_H_
#define SCANNER_H_

class Scanner {
private:

public:
	Scanner();
	virtual ~Scanner();
	void nextToken();
};

#endif /* SCANNER_H_ */
