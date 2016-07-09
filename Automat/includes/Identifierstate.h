/*
 * Automat.h
 *
 *  Created on: Jul 9, 2016
 *      Author: Raphael Hippe
 */

#ifndef Identifierstate_H_
#define Identifierstate_H_

class Identifierstate: public State {
private:
  Automat* _context;
public:
  Identifierstate(Automat* context);
  void Handle();
}

#endif /* Identifierstate_H_ */
