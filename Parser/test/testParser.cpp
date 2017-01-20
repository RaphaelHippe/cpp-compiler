#include "../includes/Parser.h"
#include <iostream>

using namespace std;
int main(int argc, char **argv) {

  Parser* parser = new Parser(argv[1], argv[2]);

  parser->parse();

  cout << "works \n";

}
