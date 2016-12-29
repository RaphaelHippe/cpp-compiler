#include "../includes/Information.h"
#include "../includes/Key.h"
#include "../includes/Symboltable.h"
#include <iostream>
using namespace std;

int main(int argc, char **argv) {

Symboltable* symTable = new Symboltable();
char word[6] = "hello";

Information* myInformation = new Information(word);
cout << "myInformation->printLexem(): ";
myInformation->printLexem();
Key* myKey = symTable->insert(myInformation);

Information* testInformation = symTable->lookup(myKey);
cout << "testInformation->printLexem(): ";
testInformation->printLexem();

}
