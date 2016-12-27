# Definition der Variablen

# enthaelt die Header Files
HEADERDIR = includes

# enthaelt die Source Files
SRCDIR = src

# enthaelt die Obj Files zum Testen
OBJSDIR = objs

# enthaelt das ausfuehrbare File zum Testen
BINDIRTEST = debug

TESTDIR = test

## hier alle Object Files eintragen, ausser das File mit der Mainmethode
## darauf achten, dass letzte Zeile ohne "\" eingetragen wird

OBJS = $(OBJSDIR)/Symboltable.o \
	#$(OBJSDIR)/xx1.o \
	#$(OBJSDIR)/xxn.o


#
#		Targets zum Bauen des Tests
#

# Variante mit geringen Makefile-Kenntnissen

## Linken der Object-Files
#makeTestSymboltable: $(OBJSDIR)/Symboltable.o $(OBJSDIR)/TestSymboltable.o
#	g++ -g $(OBJSDIR)/Symboltable.o $(OBJSDIR)/TestSymboltable.o -o $(BINDIR)/SymboltableTest
#   cp $(OBJSDIR)/Symboltable.o ../projectOBJs
#
#
## compilieren der Source-files
#
#$(OBJSDIR)/Symboltable.o :  $(SRCDIR)/Symboltable.cpp $(HEADERDIR)/Symboltable.h
#	@echo "g++ $*.cpp"
#	g++ -g  -c -Wall  -o $(OBJSDIR)/Symboltable.o  $(SRCDIR)/Symboltable.cpp
#
#
#$(OBJSDIR)/TestSymboltable.o :  $(SRCDIR)/TestSymboltable.cpp $(SRCDIR)/Symboltable.h
#	@echo "g++ $*.cpp"
#	g++ -g  -c -Wall  -o $(OBJSDIR)/TestSymboltable.o  $(SRCDIR)/TestSymboltable.cpp
#


# Variante mit guten Makefile-Kenntnissen

makeTestSymboltable: CreateDirectories EntryTarget InformationTarget KeyTarget ListTarget SymboltableTarget TokenTarget TestSymboltableTarget
	g++ -g objs/Entry.o objs/Information.o objs/Key.o objs/List.o objs/Symboltable.o objs/Token.o debug/TestSymboltable.o -o debug/SymboltableTest

# $@ name des object files = name auf der linken Seite vom Doppelpunkt des Targets
# $< erste abhaengigkeit, $< das erste Element in der Liste der Abhaengigkeiten
# $@ --> linke Seite vom Doppelpunkt
# $^ --> rechte Seite vom Doppelpunkt

# $(OBJSDIR)/%.o :  $(SRCDIR)/%.cpp $(HEADERDIR)/%.h
# 	g++ -g  -c -Wall  $<  -o $@



TestSymboltableTarget: $(TESTDIR)/TestSymboltable.cpp $(HEADERDIR)/Information.h
	g++ -g  -c -Wall $(TESTDIR)/TestSymboltable.cpp -o $(BINDIRTEST)/TestSymboltable.o

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
