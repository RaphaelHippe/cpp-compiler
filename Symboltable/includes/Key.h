/*
 * Key.h
 *
 *  Created on: Jul 17, 2016
 *      Author: Raphael Hippe
 */

#ifndef Key_H_
#define Key_H_


class Key {
private:
  int myHashValue;
  int myEntryPosition;
public:
	Key();
	virtual ~Key();
  int getHashValue();
  int getEntryPosition();
  void setHashValue(int hashValue);
  void setEntryPosition(int entryPosition);

};

#endif /* Key_H_ */
