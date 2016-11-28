#include "../includes/Automat.h"
#include <iostream>

using namespace std;

void print(char teststring[], int length){

	Automat* automat;
	automat = new Automat();

	for (int i = 0; i < length-1; i++) {
		cout << "char: " << teststring[i] << " State: " << automat->handle(teststring[i]) << "  (" << i << ")" << '\n';
	}
}

int main (int argc, char* argv[]){
	// jedes Zeichen, was abbricht machen wir 2x rein
	// TODO: LEERZEICHEN?!

	char teststring[] = "12hh365  <<  aweawe 2123 ++awe .awe awe";

	int length = sizeof(teststring) / sizeof(teststring[0]);

	print(teststring, length);

	return 1;
}
