# Project: Graph

CPP      = g++.exe
CC       = gcc.exe

OBJ      = mainGraphes1.o
LINKOBJ  = mainGraphes1.o

BIN      = Graphes1.exe
CXXFLAGS = $(CXXINCS) 
CFLAGS   = $(INCS) 
RM       = rm -f

.PHONY: all all-before all-after clean clean-custom

all: all-before $(BIN) all-after

clean: clean-custom
	${RM} $(OBJ) $(BIN)

$(BIN): $(OBJ)
	$(CC) $(LINKOBJ) -o $(BIN) $(LIBS)

mainGraphes1.o: mainGraphes1.c
	$(CC) -c mainGraphes1.c -o mainGraphes1.o $(CFLAGS)
