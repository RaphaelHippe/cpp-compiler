# Linken der Object-files, abhaengig von AutomatTarget und TestAutomatTarget
# flag:
# -g --> debug Informationen erzeugen
# -o --> name des output-files

# Definition der Variablen
INCLUDESDIR = includes
SRCDIR = src
OBJSDIR = objs
DEBUGDIR = debug
TESTSDIR = tests


makeTestAutomat: CreateDirectories SignTarget IntegerTarget IdentifierTarget InitstateTarget AutomatTarget TestAutomatTarget
	g++ -g $(OBJSDIR)/Initstate.o $(OBJSDIR)/Signstate.o $(OBJSDIR)/Integerstate.o $(OBJSDIR)/Identifierstate.o $(OBJSDIR)/Automat.o $(DEBUGDIR)/TestAutomat.o -o $(DEBUGDIR)/AutomatTest

# in makeTestAutomat include all new objs ;)

# compilieren des Files Automat.cpp zu Automat.o,
# das Objekt-File ist abhängig von $(SRCDIR)/Automat.cpp und $(SRCDIR)/Automat.h
# flag:
# -c --> nur compilieren
# -g --> debug Informationen erzeugen
# -Wall --> alle meldungen erzeugen (Warning all)

AutomatTarget: $(SRCDIR)/Automat.cpp includes/Automat.h
	g++ -g  -c -Wall $(SRCDIR)/Automat.cpp -o $(OBJSDIR)/Automat.o

# TestAutomat.o ist abhängig von tests/TestAutomat.cpp und $(SRCDIR)/Automat.h
TestAutomatTarget: $(TESTSDIR)/TestAutomat.cpp $(INCLUDESDIR)/Automat.h
	g++ -g  -c -Wall $(TESTSDIR)/TestAutomat.cpp -o $(DEBUGDIR)/TestAutomat.o

IdentifierTarget: $(SRCDIR)/Identifierstate.cpp includes/Identifierstate.h
	g++ -g  -c -Wall $(SRCDIR)/Identifierstate.cpp -o $(OBJSDIR)/Identifierstate.o

SignTarget: $(SRCDIR)/Signstate.cpp includes/Signstate.h
	g++ -g  -c -Wall $(SRCDIR)/Signstate.cpp -o $(OBJSDIR)/Signstate.o

IntegerTarget: $(SRCDIR)/Integerstate.cpp includes/Integerstate.h
	g++ -g  -c -Wall $(SRCDIR)/Integerstate.cpp -o $(OBJSDIR)/Integerstate.o

StateTarget: $(SRCDIR)/State.cpp includes/State.h
	g++ -g  -c -Wall $(SRCDIR)/State.cpp -o $(OBJSDIR)/State.o

InitstateTarget: $(SRCDIR)/Initstate.cpp includes/Initstate.h
	g++ -g  -c -Wall $(SRCDIR)/Initstate.cpp -o $(OBJSDIR)/Initstate.o

BuildExecutable:
	g++ -g $(OBJSDIR)/Automat.o $(DEBUGDIR)/TestAutomat.o -o $(DEBUGDIR)/AutomatTest

# # TestAutomat.o ist abhängig von $(SRCDIR)/TestAutomat.cpp und $(SRCDIR)/Automat.h
# TestInitstateTarget :  $(SRCDIR)/TestInitstate.cpp includes/Initstate.h
# 	g++ -g  -c -Wall $(SRCDIR)/TestInitstate.cpp  -o $(DEBUGDIR)/TestInitstate.o



# loeschen aller files im verzeichnis obj und debug, dann neu erzeugen

cleanAutomat:
	rm -f $(OBJSDIR)/*.o
	rm -f $(DEBUGDIR)/*
	# $(MAKE) makeTestAutomat

CreateDirectories:
	rm -rf $(DEBUGDIR)
	rm -rf $(OBJSDIR)
	mkdir $(DEBUGDIR)
	mkdir $(OBJSDIR)

# dieses Target wird vom makefile des Gesamtprojekts verwendet
# objs fuer Gesamtprojekt loeschen und dann neu erzeugen
AutomatOBJTarget:
	$(MAKE) AutomatTarget
