# Definition der Variablen
INCLUDESDIR = includes
SRCDIR = src
OBJSDIR = objs
DEBUGDIR = debug
TESTSDIR = tests

#
#		Targets zum Bauen des Tests
#

# Linken der Object-files, abhaengig von BufferTarget und TestBufferTarget
# flag:
# -g --> debug Informationen erzeugen
# -o --> name des output-files

makeTestBuffer: CreateDirectories BufferTarget TestBufferTarget
	g++ -g $(OBJSDIR)/Buffer.o $(DEBUGDIR)/TestBuffer.o -o $(DEBUGDIR)/BufferTest

# compilieren der Source-files
# Buffer.o ist abhaengig von Buffer.cpp und Buffer.h
# flag:
# -c --> nur compilieren
# -g --> debug Informationen erzeugen
# -Wall --> alle meldungen erzeugen (Warning all)

BufferTarget :  $(SRCDIR)/Buffer.cpp $(INCLUDESDIR)/Buffer.h
	g++ -g  -c -Wall  $(SRCDIR)/Buffer.cpp -o $(DEBUGDIR)/Buffer.o

#TestBuffer.o ist abhaengig von TestBuffer.cpp und Buffer.h
TestBufferTarget :  $(TESTSDIR)/TestBuffer.cpp $(INCLUDESDIR)/Buffer.h
	g++ -g  -c -Wall $(TESTSDIR)/TestBuffer.cpp -o $(DEBUGDIR)/TestBuffer.o

# loeschen aller files im verzeichnis $(OBJDIR) und $(BINDIRTEST) und neu compilieren

cleanBuffer:
	rm -f $(OBJSDIR)/*.o
	rm -f $(DEBUGDIR)/*
	$(MAKE) makeTestBuffer

CreateDirectories:
	rm -rf $(DEBUGDIR)
	rm -rf $(OBJSDIR)
	mkdir $(DEBUGDIR)
	mkdir $(OBJSDIR)

# dieses Target wird vom makefile des Gesamtprojekts verwendet
# objs fuer GesamtProjekt loeschen und dann neu erzeugen
BufferOBJTarget:
	$(MAKE) BufferTarget
