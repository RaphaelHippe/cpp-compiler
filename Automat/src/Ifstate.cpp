#include "../includes/Ifstate.h"

Ifstate::Ifstate(Automat* context) {
	// TODO Auto-generated constructor stub
  _context = context;
}

Ifstate::~Ifstate() {
	// TODO Auto-generated destructor stub
}

void Ifstate::handle(char c){
  // logic of the state....

  // set next state:
  // _context->setState( new Signstate(_context));
}
