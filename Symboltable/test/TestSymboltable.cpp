#include "../includes/Entry.h"
#include "../includes/Information.h"
#include "../includes/Key.h"
#include "../includes/List.h"
#include "../includes/Symboltable.h"
#include "../includes/Token.h"

int main(int argc, char **argv) {

	// symTable = new Symboltable();
	char word[4] = "abc";
	Information* myInformation = new Information(word);
	myInformation->printLexem();

	return 1;

}
