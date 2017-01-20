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

SCANNERDIR = ../Scanner
MAINDIR = ../

makeParser: CreateDirectories makeNodes ExpTarget makeArr makeDecls makeExpII makeIndex makeOpExp makeStatement makeStatements DeclTarget OpTarget ProgTarget ParsetreeTarget ParserTarget

makeNodes: NodeTarget LeafTarget IdentifierTarget IntegerNTarget

makeArr: ArrTarget ArrEpsilonTarget

makeDecls: DeclsTarget DeclsEpsilonTarget

makeExpII: ExpIITarget ExpIIExpTarget ExpIIIndexTarget ExpIIIntegerTarget ExpIINegativeTarget ExpIINotTarget

makeIndex: IndexTarget IndexEpsilonTarget

makeOpExp: OpExpTarget OpExpEpsilonTarget

makeStatement: StatementTarget StatementAssignTarget StatementBracketTarget StatementIfElseTarget StatementReadTarget StatementWhileTarget StatementWriteTarget

makeStatements: StatementsTarget StatementsEpsilonTarget

#executable Tests
#makeTestAutomat: CreateDirectories SignTarget IntegerTarget IdentifierTarget InitstateTarget AutomatTarget TestAutomatTarget
#	g++ -g $(OBJSDIR)/Initstate.o $(OBJSDIR)/Signstate.o $(OBJSDIR)/Integerstate.o $(OBJSDIR)/Identifierstate.o $(OBJSDIR)/Automat.o $(DEBUGDIR)/TestAutomat.o -o $(DEBUGDIR)/AutomatTest

TestParserTarget: $(TESTSDIR)/testParser.cpp $(INCLUDESDIR)/Parser.h
	g++ -g  -c -Wall $(TESTSDIR)/testParser.cpp -o $(DEBUGDIR)/TestParser.o

#building Testfiles
ArrTarget: $(SRCDIR)/Arr.cpp includes/Arr.h
	g++ -g  -c -Wall $(SRCDIR)/Arr.cpp -o $(OBJSDIR)/Arr.o

ArrEpsilonTarget: $(SRCDIR)/ArrEpsilon.cpp includes/ArrEpsilon.h
	g++ -g  -c -Wall $(SRCDIR)/ArrEpsilon.cpp -o $(OBJSDIR)/ArrEpsilon.o

DeclTarget: $(SRCDIR)/Decl.cpp includes/Decl.h
	g++ -g  -c -Wall $(SRCDIR)/Decl.cpp -o $(OBJSDIR)/Decl.o

DeclsTarget: $(SRCDIR)/Decls.cpp includes/Decls.h
	g++ -g  -c -Wall $(SRCDIR)/Decls.cpp -o $(OBJSDIR)/Decls.o

DeclsEpsilonTarget: $(SRCDIR)/DeclsEpsilon.cpp includes/DeclsEpsilon.h
	g++ -g  -c -Wall $(SRCDIR)/DeclsEpsilon.cpp -o $(OBJSDIR)/DeclsEpsilon.o

ExpTarget: $(SRCDIR)/Exp.cpp includes/Exp.h
	g++ -g  -c -Wall $(SRCDIR)/Exp.cpp -o $(OBJSDIR)/Exp.o

ExpIITarget: $(SRCDIR)/ExpII.cpp includes/ExpII.h
	g++ -g  -c -Wall $(SRCDIR)/ExpII.cpp -o $(OBJSDIR)/ExpII.o

ExpIIExpTarget: $(SRCDIR)/ExpIIExp.cpp includes/ExpIIExp.h
	g++ -g  -c -Wall $(SRCDIR)/ExpIIExp.cpp -o $(OBJSDIR)/ExpIIExp.o

ExpIIIndexTarget: $(SRCDIR)/ExpIIIndex.cpp includes/ExpIIIndex.h
	g++ -g  -c -Wall $(SRCDIR)/ExpIIIndex.cpp -o $(OBJSDIR)/ExpIIIndex.o

ExpIIIntegerTarget: $(SRCDIR)/ExpIIInteger.cpp includes/ExpIIInteger.h
	g++ -g  -c -Wall $(SRCDIR)/ExpIIInteger.cpp -o $(OBJSDIR)/ExpIIInteger.o

ExpIINegativeTarget: $(SRCDIR)/ExpIINegative.cpp includes/ExpIINegative.h
	g++ -g  -c -Wall $(SRCDIR)/ExpIINegative.cpp -o $(OBJSDIR)/ExpIINegative.o

ExpIINotTarget: $(SRCDIR)/ExpIINot.cpp includes/ExpIINot.h
	g++ -g  -c -Wall $(SRCDIR)/ExpIINot.cpp -o $(OBJSDIR)/ExpIINot.o

IndexTarget: $(SRCDIR)/Index.cpp includes/Index.h
	g++ -g  -c -Wall $(SRCDIR)/Index.cpp -o $(OBJSDIR)/Index.o

IndexEpsilonTarget: $(SRCDIR)/IndexEpsilon.cpp includes/IndexEpsilon.h
	g++ -g  -c -Wall $(SRCDIR)/IndexEpsilon.cpp -o $(OBJSDIR)/IndexEpsilon.o

LeafTarget: $(SRCDIR)/Leaf.cpp includes/Leaf.h
	g++ -g  -c -Wall $(SRCDIR)/Leaf.cpp -o $(OBJSDIR)/Leaf.o

NodeTarget: $(SRCDIR)/Node.cpp includes/Node.h
	g++ -g  -c -Wall $(SRCDIR)/Node.cpp -o $(OBJSDIR)/Node.o

OpTarget: $(SRCDIR)/Op.cpp includes/Op.h
	g++ -g  -c -Wall $(SRCDIR)/Op.cpp -o $(OBJSDIR)/Op.o

OpExpTarget: $(SRCDIR)/OpExp.cpp includes/OpExp.h
	g++ -g  -c -Wall $(SRCDIR)/OpExp.cpp -o $(OBJSDIR)/OpExp.o

OpExpEpsilonTarget: $(SRCDIR)/OpExpEpsilon.cpp includes/OpExpEpsilon.h
	g++ -g  -c -Wall $(SRCDIR)/OpExpEpsilon.cpp -o $(OBJSDIR)/OpExpEpsilon.o

ParserTarget: $(SRCDIR)/Parser.cpp includes/Parser.h
	g++ -g  -c -Wall $(SRCDIR)/Parser.cpp -o $(OBJSDIR)/Parser.o

ParsetreeTarget: $(SRCDIR)/Parsetree.cpp includes/Parsetree.h
	g++ -g  -c -Wall $(SRCDIR)/Parsetree.cpp -o $(OBJSDIR)/Parsetree.o

ProgTarget: $(SRCDIR)/Prog.cpp includes/Prog.h
	g++ -g  -c -Wall $(SRCDIR)/Prog.cpp -o $(OBJSDIR)/Prog.o

StatementTarget: $(SRCDIR)/Statement.cpp includes/Statement.h
	g++ -g  -c -Wall $(SRCDIR)/Statement.cpp -o $(OBJSDIR)/Statement.o

StatementAssignTarget: $(SRCDIR)/StatementAssign.cpp includes/StatementAssign.h
	g++ -g  -c -Wall $(SRCDIR)/StatementAssign.cpp -o $(OBJSDIR)/StatementAssign.o

StatementBracketTarget: $(SRCDIR)/StatementBracket.cpp includes/StatementBracket.h
	g++ -g  -c -Wall $(SRCDIR)/StatementBracket.cpp -o $(OBJSDIR)/StatementBracket.o

StatementIfElseTarget: $(SRCDIR)/StatementIfElse.cpp includes/StatementIfElse.h
	g++ -g  -c -Wall $(SRCDIR)/StatementIfElse.cpp -o $(OBJSDIR)/StatementIfElse.o

StatementReadTarget: $(SRCDIR)/StatementRead.cpp includes/StatementRead.h
	g++ -g  -c -Wall $(SRCDIR)/StatementRead.cpp -o $(OBJSDIR)/StatementRead.o

StatementWhileTarget: $(SRCDIR)/StatementWhile.cpp includes/StatementWhile.h
	g++ -g  -c -Wall $(SRCDIR)/StatementWhile.cpp -o $(OBJSDIR)/StatementWhile.o

StatementWriteTarget: $(SRCDIR)/StatementWrite.cpp includes/StatementWrite.h
	g++ -g  -c -Wall $(SRCDIR)/StatementWrite.cpp -o $(OBJSDIR)/StatementWrite.o

StatementsTarget: $(SRCDIR)/Statements.cpp includes/Statements.h
	g++ -g  -c -Wall $(SRCDIR)/Statements.cpp -o $(OBJSDIR)/Statements.o

StatementsEpsilonTarget: $(SRCDIR)/StatementsEpsilon.cpp includes/StatementsEpsilon.h
	g++ -g  -c -Wall $(SRCDIR)/StatementsEpsilon.cpp -o $(OBJSDIR)/StatementsEpsilon.o

IdentifierTarget: $(SRCDIR)/Identifier.cpp includes/Identifier.h
	g++ -g  -c -Wall $(SRCDIR)/Identifier.cpp -o $(OBJSDIR)/Identifier.o

IntegerNTarget: $(SRCDIR)/IntegerN.cpp includes/IntegerN.h
	g++ -g  -c -Wall $(SRCDIR)/IntegerN.cpp -o $(OBJSDIR)/IntegerN.o

BuildExecutable: MakeAll TestParserTarget
	g++ -g $(OBJSDIR)/Parser.o $(DEBUGDIR)/TestParser.o -o $(DEBUGDIR)/ParserTest

MakeAll:
	$(MAKE) -C $(MAINDIR) all


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
