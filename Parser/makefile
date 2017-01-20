# Linken der Object-files, abhaengig von ParserTarget und TestParserTarget
# flag:
# -g --> debug Informationen erzeugen
# -o --> name des output-files

# Definition der Variablen
INCLUDESDIR = includes
SRCDIR = src
OBJSDIR = objs
DEBUGDIR = debug
TESTSDIR = test

makeParser: CreateDirectories ArrTarget DeclTarget DeclsTarget ExpTarget ExpIITarget IndexTarget LeafTarget NodeTarget OpTarget OpExpTarget ParserTarget ProgTarget StatementTarget StatementsTarget

#executable Tests
#makeTestAutomat: CreateDirectories SignTarget IntegerTarget IdentifierTarget InitstateTarget AutomatTarget TestAutomatTarget
#	g++ -g $(OBJSDIR)/Initstate.o $(OBJSDIR)/Signstate.o $(OBJSDIR)/Integerstate.o $(OBJSDIR)/Identifierstate.o $(OBJSDIR)/Automat.o $(DEBUGDIR)/TestAutomat.o -o $(DEBUGDIR)/AutomatTest

#TestAutomatTarget: $(TESTSDIR)/TestAutomat.cpp $(INCLUDESDIR)/Automat.h
#	g++ -g  -c -Wall $(TESTSDIR)/TestAutomat.cpp -o $(DEBUGDIR)/TestAutomat.o

#building Testfiles
ArrTarget: $(SRCDIR)/Arr.cpp includes/Arr.h
	g++ -g  -c -Wall $(SRCDIR)/Arr.cpp -o $(OBJSDIR)/Arr.o

DeclTarget: $(SRCDIR)/Decl.cpp includes/Decl.h
	g++ -g  -c -Wall $(SRCDIR)/Decl.cpp -o $(OBJSDIR)/Decl.o

DeclsTarget: $(SRCDIR)/Decls.cpp includes/Decls.h
	g++ -g  -c -Wall $(SRCDIR)/Decls.cpp -o $(OBJSDIR)/Decls.o

ExpTarget: $(SRCDIR)/Exp.cpp includes/Exp.h
	g++ -g  -c -Wall $(SRCDIR)/Exp.cpp -o $(OBJSDIR)/Exp.o

ExpIITarget: $(SRCDIR)/ExpII.cpp includes/ExpII.h
	g++ -g  -c -Wall $(SRCDIR)/ExpII.cpp -o $(OBJSDIR)/ExpII.o

IndexTarget: $(SRCDIR)/Index.cpp includes/Index.h
	g++ -g  -c -Wall $(SRCDIR)/Index.cpp -o $(OBJSDIR)/Index.o

LeafTarget: $(SRCDIR)/Leaf.cpp includes/Leaf.h
	g++ -g  -c -Wall $(SRCDIR)/Leaf.cpp -o $(OBJSDIR)/Leaf.o

NodeTarget: $(SRCDIR)/Node.cpp includes/Node.h
	g++ -g  -c -Wall $(SRCDIR)/Node.cpp -o $(OBJSDIR)/Node.o

OpTarget: $(SRCDIR)/Op.cpp includes/Op.h
	g++ -g  -c -Wall $(SRCDIR)/Op.cpp -o $(OBJSDIR)/Op.o

OpExpTarget: $(SRCDIR)/OpExp.cpp includes/OpExp.h
	g++ -g  -c -Wall $(SRCDIR)/OpExp.cpp -o $(OBJSDIR)/OpExp.o

ParserTarget: $(SRCDIR)/Parser.cpp includes/Parser.h
	g++ -g  -c -Wall $(SRCDIR)/Parser.cpp -o $(OBJSDIR)/Parser.o

ProgTarget: $(SRCDIR)/Prog.cpp includes/Prog.h
	g++ -g  -c -Wall $(SRCDIR)/Prog.cpp -o $(OBJSDIR)/Prog.o

StatementTarget: $(SRCDIR)/Statement.cpp includes/Statement.h
	g++ -g  -c -Wall $(SRCDIR)/Statement.cpp -o $(OBJSDIR)/Statement.o

StatementsTarget: $(SRCDIR)/Statements.cpp includes/Statements.h
	g++ -g  -c -Wall $(SRCDIR)/Statements.cpp -o $(OBJSDIR)/Statements.o

#BuildExecutable:
#	g++ -g $(OBJSDIR)/Automat.o $(DEBUGDIR)/TestAutomat.o -o $(DEBUGDIR)/AutomatTest

# loeschen aller files im verzeichnis obj und debug, dann neu erzeugen
cleanParser:
	rm -f $(OBJSDIR)/*.o
	rm -f $(DEBUGDIR)/*

CreateDirectories:
	rm -rf $(DEBUGDIR)
	rm -rf $(OBJSDIR)
	mkdir $(DEBUGDIR)
	mkdir $(OBJSDIR)
	# $(MAKE) makeTestAutomat

# dieses Target wird vom makefile des Gesamtprojekts verwendet
# objs fuer Gesamtprojekt loeschen und dann neu erzeugen
ParserOBJTarget:
	$(MAKE) makeParser
