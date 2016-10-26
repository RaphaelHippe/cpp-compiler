#include "../includes/Scanner.h"

int main(int argc, char **argv) {

	Scanner* scanner;
	Token* token;
	scanner = new Scanner();

	token = scanner->nextToken();
	if (token == NULL) {
		/* code */
		cout << "NULL";
	} else {
		cout << "TOKEN";
		// cout << token->getTokenString();
	}

}
