/*
 * List.h
 *
 *  Created on: Jul 17, 2016
 *      Author: Raphael Hippe
 */
 #include "../includes/Information.h"
 #include "../includes/Entry.h"


#ifndef List_H_
#define List_H_


class List {
private:
  int listSize;
  Entry* head;
public:
	List();
	virtual ~List();
  int addValue(Information* value);
  int getListSize();
  Information* getInformation(int position);
};

#endif /* List_H_ */
