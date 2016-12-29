#include "../includes/Information.h"

int main(int argc, char **argv) {

	// symTable = new Symboltable();
	char word[4] = "abc";
	Information* myInformation = new Information(word);
	myInformation->printLexem();

	return 1;

}
