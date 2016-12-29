/*
 * Entry.h
 *
 *  Created on: Jul 17, 2016
 *      Author: Raphael Hippe
 */

 #include "../includes/Information.h"

#ifndef Entry_H_
#define Entry_H_

class Entry {
private:
  Information* myValue;
  Entry* myNext;
public:
	Entry(Information* value);
	virtual ~Entry();
  int addValue(Information* value);
  Information* getValue(int position);

};

#endif /* Entry_H_ */
