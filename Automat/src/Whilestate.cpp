#include "../includes/Whilestate.h"

Whilestate::Whilestate(Automat* context) {
	_context = context;
}

Whilestate::~Whilestate() {
}

void Whilestate::handle(char c){
  // logic of the state....

  // set next state:
  // _context->setState( new Signstate(_context));
}
