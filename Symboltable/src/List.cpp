/*
 * List.cpp
 *
 *  Created on: Jul 17, 2016
 *      Author: Raphael Hippe
 */

#include "../includes/List.h"
#include <stdio.h>

List::List() {
	// TODO Auto-generated constructor stub
  listSize = 0;
  head = NULL;
}

int List::addValue(Information* value){
  ++listSize;
  if (head == NULL) {
    // if list is empty make value the new head
    head = new Entry(value);
    return 0;
  } else {
    // if list is not empty add value at the end
    return head->addValue(value);
  }
}

Information* List::getInformation(int position){
  return head->getValue(position);
}

int List::getListSize(){
  return listSize;
}

List::~List() {
	// TODO Auto-generated destructor stub
}
