#include "../../Scanner/includes/Scanner.h"
#include "../../Parser/includes/Parser.h"
#include <iostream>

using namespace std;
int main(int argc, char **argv) {


	Parser* parser = new Parser(argv[1], argv[2]);
	cout << "Lets get this party started!";
	cout << '\n';
	do {
		// cout << "Scanning next Token!";
		// cout << '\n';
	} while(parser->parse() == 1);
	cout << "done \n";

}
