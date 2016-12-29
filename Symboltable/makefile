HEADERDIR = includes
SRCDIR = src
OBJSDIR = objs
BINDIRTEST = debug

TESTDIR = test
OBJS = $(OBJSDIR)/Symboltable.o \
	#$(OBJSDIR)/xx1.o \
	#$(OBJSDIR)/xxn.o

makeSymboltable: CreateDirectories EntryTarget InformationTarget KeyTarget ListTarget SymboltableTarget TokenTarget

#executable Tests
makeTestInformation: CreateDirectories InformationTarget TestInformationTarget
	g++ -g objs/Information.o debug/TestInformation.o -o debug/InformationTest

makeTestKey: CreateDirectories EntryTarget InformationTarget KeyTarget ListTarget SymboltableTarget TestKeyTarget
	g++ -g objs/Entry.o objs/Information.o objs/Key.o objs/List.o objs/Symboltable.o debug/TestKey.o -o debug/KeyTest

makeTestSymboltable: CreateDirectories EntryTarget InformationTarget KeyTarget ListTarget SymboltableTarget TokenTarget TestSymboltableTarget
	g++ -g objs/Entry.o objs/Information.o objs/Key.o objs/List.o objs/Symboltable.o objs/Token.o debug/TestSymboltable.o -o debug/SymboltableTest

#building Testfiles
TestInformationTarget: $(TESTDIR)/TestInformation.cpp $(HEADERDIR)/Information.h
		g++ -g  -c -Wall $(TESTDIR)/TestInformation.cpp -o $(BINDIRTEST)/TestInformation.o

TestKeyTarget: $(TESTDIR)/TestKey.cpp
		g++ -g  -c -Wall $(TESTDIR)/TestKey.cpp -o $(BINDIRTEST)/TestKey.o

TestSymboltableTarget: $(TESTDIR)/TestSymboltable.cpp $(HEADERDIR)/Information.h
	g++ -g  -c -Wall $(TESTDIR)/TestSymboltable.cpp -o $(BINDIRTEST)/TestSymboltable.o

#building real Files
EntryTarget: src/Entry.cpp includes/Entry.h
		g++ -g  -c -Wall src/Entry.cpp -o objs/Entry.o

InformationTarget: src/Information.cpp includes/Information.h
	g++ -g  -c -Wall src/Information.cpp -o objs/Information.o

KeyTarget: src/Key.cpp includes/Key.h
	g++ -g  -c -Wall src/Key.cpp -o objs/Key.o

ListTarget: src/List.cpp includes/List.h
	g++ -g  -c -Wall src/List.cpp -o objs/List.o

SymboltableTarget: src/Symboltable.cpp includes/Symboltable.h
		g++ -g  -c -Wall src/Symboltable.cpp -o objs/Symboltable.o

TokenTarget: src/Token.cpp includes/Token.h
	g++ -g  -c -Wall src/Token.cpp -o objs/Token.o

# loeschen aller files im verzeichnis $(OBJSDIR) und $(BINDIRTEST) und neu compilieren

cleanSymboltable:
	rm -rf $(OBJSDIR)/*.o
	rm -rf $(BINDIRTEST)/*
	$(MAKE) makeTestSymboltable

CreateDirectories:
	rm -rf debug
	rm -rf objs
	mkdir debug
	mkdir objs

## objs fuer GesamtProjekt neu erzeugen
SymboltableOBJTarget:
	$(MAKE) SymboltableTarget
