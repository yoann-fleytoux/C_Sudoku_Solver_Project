
CC=gcc
OPT=-Wall
EXEC=MonAppli

all:$(EXEC)

chainediff.o:Niveau2sudoku.c
	$(CC) -o Niveau2sudoku.o -c Niveau2sudoku.c $(OPT)

main.o:main2.c
	$(CC) -o main2.o -c main2.c $(OPT)

$(EXEC):main2.o Niveau2sudoku.o
	$(CC) main2.o Niveau2sudoku.o -o $(EXEC)

clean:
	rm -rf *.o *.exe *.stackdump