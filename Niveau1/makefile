
CC=gcc
OPT=-Wall
EXEC=MonAppli

all:$(EXEC)

chainediff.o:Niveau1sudoku.c
	$(CC) -o Niveau1sudoku.o -c Niveau1sudoku.c $(OPT)

main.o:main1.c
	$(CC) -o main1.o -c main1.c $(OPT)

$(EXEC):main1.o Niveau1sudoku.o
	$(CC) main1.o Niveau1sudoku.o -o $(EXEC)

clean:
	rm -rf *.o *.exe *.stackdump