#include "../includes/Identifier.h"
#include <iostream>

using namespace std;
Identifier::Identifier(Token* token) {
  this->token = token;
}

Identifier::~Identifier() {
}
