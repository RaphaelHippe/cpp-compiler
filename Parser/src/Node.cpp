#include "../includes/Node.h"

int Node::labelCount = 0;
bool Node::error = false;

void Node::addNode() {}

void Node::typeCheck() {}

void Node::makeCode() {}


int Node::getLabelcount(){
  return labelCount++;
}

bool Node::getError(){
  return error;
}

void Node::setError() {
  error = true;
}
