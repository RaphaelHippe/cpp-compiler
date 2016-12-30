#include "../includes/Information.h"
#include <iostream>

using namespace std;

int main(int argc, char **argv) {

	char word[4] = "asd";
	Information* myInformation = new Information(word);
	Information* myInformation2 = new Information(word);
	myInformation->printLexem();
	myInformation2->printLexem();
	myInformation->resetLexemPointer();
	myInformation2->resetLexemPointer();
	if(myInformation->compairLexem(myInformation2->getLexemPointer())){
		cout << "works" << '\n';
	} else {
		cout << "doesnt work" << '\n';
	}
}
