#include "../includes/Automat.h"
#include <iostream>

using namespace std;

void print(char teststring[], int length){

	Automat* automat;
	automat = new Automat();
	int state;

	for (int i = 0; i < length-1; i++) {
		state = automat->handle(teststring[i]);

		if (state == 0) {
			cout << '\n';
			i--;
		} else if(state == 1){
			cout << teststring[i];
		}	else {
			cout << "  (" << i << ")" << " State: " << state << " Char: "<< teststring[i];
		}
	}
	cout << '\n';
}

int main (int argc, char* argv[]){
	// jedes Zeichen, was abbricht machen wir 2x rein
	// TODO: LEERZEICHEN?!

	char teststring[] = "12hh365aaawe123a++123  +123+123awea awe//123aaa&&a&&we";

	int length = sizeof(teststring) / sizeof(teststring[0]);

	print(teststring, length);

	return 1;
}
