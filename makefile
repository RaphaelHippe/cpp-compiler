#
#	baut das komplette Scanner Projekt
#
OBJDIR = objs
AUTOMATDIR = Automat
BUFFERDIR = Buffer
SYMBOLTABLEDIR = Symboltable
SCANNERDIR = Scanner

all: mainTarget
	g++ -g Automat/objs/*.o Buffer/objs/*.o  Scanner/objs/*.o Symboltable/objs/*.o main/objs/main.o -o main/dist/main
# rm 	remove
# -f	force, ohne nachfragen
clean:
	rm -f $(AUTOMATDIR)/$(OBJDIR)/*.o
	rm -f $(BUFFERDIR)/$(OBJDIR)/*.o
	rm -f $(SYMBOLTABLEDIR)/$(OBJDIR)/*.o
	rm -f $(SCANNERDIR)/$(OBJDIR)/*.o
	rm -f $(SCANNERDIR)/debug/*

makeMain: automatOBJs bufferOBJs symboltableOBJs scannerOBJTarget
	g++ -g $(OBJSDIR)/Buffer.o $(DEBUGDIR)/TestBuffer.o -o $(DEBUGDIR)/BufferTest

mainTarget : automatOBJs bufferOBJs symboltableOBJs scannerOBJTarget main/src/main.cpp
	g++ -g  -c -Wall  main/src/main.cpp -o main/objs/main.o

automatOBJs:
	$(MAKE) -C $(AUTOMATDIR) AutomatOBJTarget


bufferOBJs:
	$(MAKE) -C $(BUFFERDIR) BufferOBJTarget


symboltableOBJs:
	$(MAKE) -C $(SYMBOLTABLEDIR) SymboltableOBJTarget


scannerOBJTarget:
	$(MAKE) -C $(SCANNERDIR) ScannerOBJTarget
