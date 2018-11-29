# This is a comment
# target: prereqs
# recipe

EXE = example
cc = gcc
CFLAGS = -c
SRCS = $(wildcard *.c *.h)
#$(patsub PATTER, REPLACEMENT, TEXT)
OBJECTS = $(patsubst %,c, %,c, $(SRCS))
all: $(EXE)

$(EXE): ben_example.o ben_helpers.o
	$(cc) ben_example.o ben_helpers.o -o $(EXE) 

ben_example.o: ben_example.c
	$(cc) ben_example.c -c

ben_helpers.o: ben_helpers.c
	$(cc) ben_helpers.c -c

clean:
	rm -rf *.o $(EXE)
