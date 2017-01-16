# Linken der Object-files, abhaengig von AutomatTarget und TestAutomatTarget
# flag:
# -g --> debug Informationen erzeugen
# -o --> name des output-files

# Definition der Variablen
INCLUDESDIR = includes
SRCDIR = src
OBJSDIR = objs
DEBUGDIR = debug
TESTSDIR = test

makeAutomat: CreateDirectories SignTarget IntegerTarget IdentifierTarget InitstateTarget AutomatTarget

#executable Tests
makeTestAutomat: CreateDirectories SignTarget IntegerTarget IdentifierTarget InitstateTarget AutomatTarget TestAutomatTarget
	g++ -g $(OBJSDIR)/Initstate.o $(OBJSDIR)/Signstate.o $(OBJSDIR)/Integerstate.o $(OBJSDIR)/Identifierstate.o $(OBJSDIR)/Automat.o $(DEBUGDIR)/TestAutomat.o -o $(DEBUGDIR)/AutomatTest

TestAutomatTarget: $(TESTSDIR)/TestAutomat.cpp $(INCLUDESDIR)/Automat.h
	g++ -g  -c -Wall $(TESTSDIR)/TestAutomat.cpp -o $(DEBUGDIR)/TestAutomat.o

#building Testfiles
AutomatTarget: $(SRCDIR)/Automat.cpp includes/Automat.h
	g++ -g  -c -Wall $(SRCDIR)/Automat.cpp -o $(OBJSDIR)/Automat.o

IdentifierTarget: $(SRCDIR)/Identifierstate.cpp includes/Identifierstate.h
	g++ -g  -c -Wall $(SRCDIR)/Identifierstate.cpp -o $(OBJSDIR)/Identifierstate.o

InitstateTarget: $(SRCDIR)/Initstate.cpp includes/Initstate.h
	g++ -g  -c -Wall $(SRCDIR)/Initstate.cpp -o $(OBJSDIR)/Initstate.o

IntegerTarget: $(SRCDIR)/Integerstate.cpp includes/Integerstate.h
	g++ -g  -c -Wall $(SRCDIR)/Integerstate.cpp -o $(OBJSDIR)/Integerstate.o

SignTarget: $(SRCDIR)/Signstate.cpp includes/Signstate.h
	g++ -g  -c -Wall $(SRCDIR)/Signstate.cpp -o $(OBJSDIR)/Signstate.o

BuildExecutable:
	g++ -g $(OBJSDIR)/Automat.o $(DEBUGDIR)/TestAutomat.o -o $(DEBUGDIR)/AutomatTest

# loeschen aller files im verzeichnis obj und debug, dann neu erzeugen
cleanAutomat:
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
AutomatOBJTarget:
	$(MAKE) makeAutomat
