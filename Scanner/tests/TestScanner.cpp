#include "../includes/Scanner.h"
#include <iostream>

using namespace std;
int main(int argc, char **argv) {

	Scanner* scanner;
	// Token* token;
	scanner = new Scanner();

	do {
		/* code */
		cout << "Scanning next Token!";
		cout << '\n';
	} while(scanner->nextToken() == 1);


	//
	// token = scanner->nextToken();
	// if (token == NULL) {
	// 	/* code */
	// 	cout << "NULL";
	// } else {
	// 	cout << "TOKEN";
	// 	// cout << token->getTokenString();
	// }

}
