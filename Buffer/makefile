# Definition der Variablen
INCLUDESDIR = includes
SRCDIR = src
OBJSDIR = objs
DEBUGDIR = debug
TESTSDIR = test

makeBuffer: CreateDirectories BufferTarget

makeTestBuffer: CreateDirectories BufferTarget TestBufferTarget
	g++ -g $(OBJSDIR)/Buffer.o $(DEBUGDIR)/TestBuffer.o -o $(DEBUGDIR)/BufferTest

BufferTarget :  $(SRCDIR)/Buffer.cpp $(INCLUDESDIR)/Buffer.h
	g++ -g  -c -Wall  $(SRCDIR)/Buffer.cpp -o $(OBJSDIR)/Buffer.o

#TestBuffer.o ist abhaengig von TestBuffer.cpp und Buffer.h
TestBufferTarget :  $(TESTSDIR)/TestBuffer.cpp $(INCLUDESDIR)/Buffer.h
	g++ -g  -c -Wall $(TESTSDIR)/TestBuffer.cpp -o $(DEBUGDIR)/TestBuffer.o

# cleanen und neu compilieren
cleanBuffer:
	rm -f $(OBJSDIR)/*.o
	rm -f $(DEBUGDIR)/*
	$(MAKE) makeTestBuffer

CreateDirectories:
	rm -rf $(DEBUGDIR)
	rm -rf $(OBJSDIR)
	mkdir $(DEBUGDIR)
	mkdir $(OBJSDIR)

BufferOBJTarget:
	$(MAKE) BufferTarget
