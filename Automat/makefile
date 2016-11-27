#
#		Targets zum Bauen des Tests
#

# Linken der Object-files, abhaengig von AutomatTarget und TestAutomatTarget
# flag:
# -g --> debug Informationen erzeugen
# -o --> name des output-files

makeTestAutomat: CreateDirectories SignTarget IntegerTarget IdentifierTarget InitstateTarget AutomatTarget TestAutomatTarget
	g++ -g objs/Initstate.o objs/Signstate.o objs/Integerstate.o objs/Identifierstate.o objs/Automat.o debug/TestAutomat.o -o debug/AutomatTest

# in makeTestAutomat include all new objs ;)

# compilieren des Files Automat.cpp zu Automat.o,
# das Objekt-File ist abhängig von src/Automat.cpp und src/Automat.h
# flag:
# -c --> nur compilieren
# -g --> debug Informationen erzeugen
# -Wall --> alle meldungen erzeugen (Warning all)

AutomatTarget: src/Automat.cpp includes/Automat.h
	g++ -g  -c -Wall src/Automat.cpp -o objs/Automat.o

# TestAutomat.o ist abhängig von src/TestAutomat.cpp und src/Automat.h
TestAutomatTarget: src/TestAutomat.cpp includes/Automat.h
	g++ -g  -c -Wall src/TestAutomat.cpp -o debug/TestAutomat.o

IdentifierTarget: src/Identifierstate.cpp includes/Identifierstate.h
	g++ -g  -c -Wall src/Identifierstate.cpp -o objs/Identifierstate.o

SignTarget: src/Signstate.cpp includes/Signstate.h
	g++ -g  -c -Wall src/Signstate.cpp -o objs/Signstate.o

IntegerTarget: src/Integerstate.cpp includes/Integerstate.h
	g++ -g  -c -Wall src/Integerstate.cpp -o objs/Integerstate.o

StateTarget: src/State.cpp includes/State.h
	g++ -g  -c -Wall src/State.cpp -o objs/State.o

InitstateTarget: src/Initstate.cpp includes/Initstate.h
	g++ -g  -c -Wall src/Initstate.cpp -o objs/Initstate.o

CreateDirectories:
	rm -rf debug
	rm -rf objs
	mkdir debug
	mkdir objs

BuildExecutable:
	g++ -g objs/Automat.o debug/TestAutomat.o -o debug/AutomatTest

# # TestAutomat.o ist abhängig von src/TestAutomat.cpp und src/Automat.h
# TestInitstateTarget :  src/TestInitstate.cpp includes/Initstate.h
# 	g++ -g  -c -Wall src/TestInitstate.cpp  -o debug/TestInitstate.o



# loeschen aller files im verzeichnis obj und debug, dann neu erzeugen

cleanAutomat:
	rm -f objs/*.o
	rm -f debug/*
	# $(MAKE) makeTestAutomat


# dieses Target wird vom makefile des Gesamtprojekts verwendet
# objs fuer Gesamtprojekt loeschen und dann neu erzeugen
AutomatOBJTarget:
	$(MAKE) AutomatTarget
