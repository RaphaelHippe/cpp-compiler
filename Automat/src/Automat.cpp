/*
 * Automat.cpp
 *
 */

#include "../includes/Automat.h"
#include <cstddef>

Automat::Automat() {
	// TODO Auto-generated constructor stub
  // set init state...
  // WHY CANT I FUCKING CREATE THIS OBJECT HERE
  // _state = new Initstate(this);
  _state = new Initstate();
}

Automat::~Automat() {
	// TODO Auto-generated destructor stub
}

// void Automat::setState(State* state) {
//   _state = state;
// }
//
int Automat::handle(char c){

  // if (c == '\0') {
  //   return Automat::UNDEFINED;
  // } else {
  //   return Automat::INIT;
  // }
  // _state = _state->handle(c)
  // return _state->handle(c);
  return 76;
}
//
// int Automat::gettype(){
//   return 1;
// }
// int Automat::getline(){
//   return 1;
// }
// int Automat::getcolumn(){
//   return 1;
// }
// int Automat::getvalue(){
//   return 1;
// }
// Information* Automat::getinformation(){
//   return NULL;
// }
