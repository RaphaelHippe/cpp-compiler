#include "../../Scanner/includes/Scanner.h"
#include "../../Parser/includes/Parser.h"
#include <iostream>

using namespace std;
int main(int argc, char **argv) {


	Parser* parser = new Parser(argv[1], argv[2]);
	cout << "Lets get this party started!";
	cout << '\n';

	Parsetree* tree = parser->parse();

	if (tree != NULL) {
		if (!tree->typeCheck()) {
			cout << "typeCheck done - no errors \n";
		} else {
			cout << "typeCheck done - errors \n";
		}
	} else {
		cout << "No Tree!\n";
	}
}
