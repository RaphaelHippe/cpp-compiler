#include "../includes/Key.h"

Key::Key() {
  myHashValue = 0;
  myEntryPosition = 0;
}

Key::~Key() {

}

void Key::setHashValue(int hashValue){
  myHashValue = hashValue;
}

void Key::setEntryPosition(int entryPosition){
  myEntryPosition = entryPosition;
}

int Key::getHashValue(){
  return myHashValue;
}

int Key::getEntryPosition(){
  return myEntryPosition;
}
