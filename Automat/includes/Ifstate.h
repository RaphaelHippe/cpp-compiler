/*
 * Automat.h
 *
 *  Created on: Jul 9, 2016
 *      Author: Raphael Hippe
 */

#ifndef Ifstate_H_
#define Ifstate_H_

class Ifstate: public State {
private:
  Automat* _context;
public:
  Ifstate(Automat* context);
  void Handle();
}

#endif /* Ifstate_H_ */
