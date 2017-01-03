#include "../../Automat/includes/Automat.h"
#include "../../Buffer/includes/Buffer.h"
#include "../../Scanner/includes/Scanner.h"
#include <iostream>

using namespace std;
int main(int argc, char **argv) {

	Scanner* scanner;
	scanner = new Scanner(argv[1], argv[2]);

	do {
		cout << "Scanning next Token!";
		cout << '\n';
	} while(scanner->nextToken() == 1);

}