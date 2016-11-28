#include "../includes/Automat.h"
#include <iostream>

using namespace std;
int main (int argc, char* argv[]){

	Automat* automat;

	automat = new Automat();
	// jedes Zeichen, was abbricht machen wir 2x rein
	// TODO: LEERZEICHEN?!
	int i;
	i = automat->handle('1');
	cout << i << '\n';
	i = automat->handle('2');
	cout << i << '\n';
	i = automat->handle('h');
	cout << i << '\n';
	i = automat->handle('h');
	cout << i << '\n';
	i = automat->handle('3');
	cout << i << '\n';
	i = automat->handle('6');
	cout << i << '\n';
	i = automat->handle('5');
	cout << i << '\n';
	i = automat->handle(' ');
	cout << i << '\n';
	i = automat->handle(' ');
	cout << i << '\n';
	i = automat->handle('<');
	cout << i << '\n';
	i = automat->handle('<');
	cout << i << '\n';
	i = automat->handle(' ');
	cout << i << '\n';
	i = automat->handle(' ');
	cout << i << '\n';

	return 1;

}
