#include "../includes/Buffer.h"
#include <iostream>

using namespace std;

int main(int argc, char **argv) {

	Buffer*  buffer;

	buffer = new Buffer(argv[1]);

	cout << argv[1] << '\n';
	char c = '1';

	int i = 0;

	while (c != '\0') {
		i++;
		c = buffer->getChar();
		cout << c;
	}
}
