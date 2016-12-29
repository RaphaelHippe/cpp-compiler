#include "../includes/Information.h"

int main(int argc, char **argv) {

	char word[33] = "myInformation->printLexem works!";
	Information* myInformation = new Information(word);
	myInformation->printLexem();
}
