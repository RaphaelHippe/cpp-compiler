/*
 * Automat.h
 *
 *  Created on: Jul 9, 2016
 *      Author: Raphael Hippe
 */

#ifndef Whilestate_H_
#define Whilestate_H_

class Whilestate: public State {
private:
  Automat* _context;
public:
  Whilestate(Automat* context);
  void Handle();
}

#endif /* Whilestate_H_ */
