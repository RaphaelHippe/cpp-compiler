#
#	baut das komplette Scanner Projekt
#
OBJDIR = objs
AUTOMATDIR = Automat
BUFFERDIR = Buffer
SYMBOLTABLEDIR = Symboltable
SCANNERDIR = Scanner
PARSERRDIR = Parser

all: CreateDirectories mainTarget
	g++ -g Automat/objs/*.o Buffer/objs/*.o Symboltable/objs/*.o Scanner/objs/*.o Parser/objs/*.o Main/objs/Main.o -o Main/dist/Main
# rm 	remove
# -f	force, ohne nachfragen
clean:
	rm -f $(AUTOMATDIR)/$(OBJDIR)/*.o
	rm -f $(BUFFERDIR)/$(OBJDIR)/*.o
	rm -f $(SYMBOLTABLEDIR)/$(OBJDIR)/*.o
	rm -f $(SCANNERDIR)/$(OBJDIR)/*.o
	rm -f $(SCANNERDIR)/debug/*

makeMain: automatOBJs bufferOBJs symboltableOBJs scannerOBJs
	g++ -g $(OBJSDIR)/Buffer.o $(DEBUGDIR)/TestBuffer.o -o $(DEBUGDIR)/BufferTest

mainTarget : automatOBJs bufferOBJs symboltableOBJs scannerOBJs parserOBJs Main/src/Main.cpp
	g++ -g  -c -Wall  Main/src/Main.cpp -o Main/objs/Main.o

automatOBJs:
	$(MAKE) -C $(AUTOMATDIR) AutomatOBJTarget

parserOBJs:
	$(MAKE) -C $(PARSERRDIR) ParserOBJTarget

bufferOBJs:
	$(MAKE) -C $(BUFFERDIR) BufferOBJTarget

symboltableOBJs:
	$(MAKE) -C $(SYMBOLTABLEDIR) SymboltableOBJTarget

scannerOBJs:
	$(MAKE) -C $(SCANNERDIR) ScannerOBJTarget

CreateDirectories:
	rm -rf Main/objs
	rm -rf Main/dist
	rm -rf Main/output
	mkdir Main/objs
	mkdir Main/dist
	mkdir Main/output
