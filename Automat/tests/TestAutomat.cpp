#include "../includes/Automat.h"
#include <iostream>

using namespace std;

void print(char teststring[], int length){

	Automat* automat;
	automat = new Automat();
	int state;

	for (int i = 0; i < length-1; i++) {
		state = automat->handle(teststring[i]);
		//
		// if (state == -2) {
		// 	i--;
		// 	cout << "ERROR: " << teststring[i];
		// 	i++;
		// 	cout << '\n';
		// }

		if (state == -1) {
			cout << "ERROR: " << teststring[i];
			cout << '\n';
		}

		if (state == 22) {
			/* code */
			cout << '?';
		}

		if (state == 21) {
			/* code */
			cout << '\n';
		}

		if (state == 20) {
			/* code */
			cout << teststring[i];
			cout << '\n';
		}

		if (state == 0) {
			cout << " Column: "<< automat->getcolumn()<< '\n';
			// cout << "->" << teststring[i];
			i--;
		} else if(state == 1){
			cout << teststring[i];
			// cout << "  (" << i << ")" << " State: " << state << " Char: "<< teststring[i];
			// cout << teststring[i] << '\n';
		}
	}
	cout << '\n';
}

int main (int argc, char* argv[]){
	// jedes Zeichen, was abbricht machen wir 2x rein
	// TODO: LEERZEICHEN?!

	// char teststring[] = "&+";
	char teststring[] = ":hal&    lo*lolol#####123lol123:*aslkdjasd####ahdakjshdasd###*:asdkasd#123";
	// char teststring[] = "hallo:*lol*lol:hallo*:hallo*:";
	// char teststring[] = "hallo++hallo&&&&=:==&&:=integer123+{123hasllo123213[]";
	// char teststring[] = "12hh365aaawe123a++123  +123+123awea awe//123aaa&&a&&we";

	int length = sizeof(teststring) / sizeof(teststring[0]);

	print(teststring, length);

	return 1;
}
