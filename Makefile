

CC=gcc
CFLAGS=-std=c11 -Wall -Wextra -g 
LDFLAGS=-lm -lcunit 

all: tests jeu

unit_test.o : unit_test.c unit_test.h grid_color.h
	${CC} ${CFLAGS} -c unit_test.c

grid_color.o: grid_color.c grid_color.h
	${CC} ${CFLAGS} -c grid_color.c

main.o: main.c  grid_color.h unit_test.h
	${CC} ${CFLAGS} -c main.c

main_jeu.o: main_jeu.c grid_color.h
	${CC} ${CFLAGS} -c main_jeu.c

tests: grid_color.o main.o unit_test.o
	${CC} ${CFLAGS} $^ -o $@ ${LDFLAGS}

jeu: grid_color.o main_jeu.o
	${CC} ${CFLAGS} $^ -o $@ ${LDFLAGS}
	
doc: Doxyfile
	doxygen Doxyfile

valgrind: valgrind --leak-check=yes ./jeu
	  valgrind --leak-check=yes ./tests
		

clean:
	rm grid_color.o main.o
