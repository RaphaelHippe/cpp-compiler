#include "../includes/Automat.h"
#include <iostream>

using namespace std;
int main (int argc, char* argv[]){

	Automat* automat;

	automat = new Automat();

	int i;
	i = automat->handle('c');
	cout << i;

	return 1;

}
