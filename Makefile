

CC=gcc
CFLAGS=-std=c11 -Wall -Wextra -g
LDFLAGS=-lm -lcunit

all: Jeu jeu_texte

#unit_test.o : unit_test.c unit_test.h struct.h
#	${CC} ${CFLAGS} -c unit_test.c

grid_color.o: grid_color.c grid_color.h
	${CC} ${CFLAGS} -c grid_color.c


SDL.o: SDL.c SDL.h grid_color.h
	${CC} ${CFLAGS} -c SDL.c 

Jeu.o: Jeu.c SDL.h grid_color.o
	${CC} ${CFLAGS} -c Jeu.c

Jeu:grid_color.o SDL.o Jeu.o
	${CC} ${CFLAGS} $^ -o $@ ${LDFLAGS} -lSDL -lSDL_ttf

main_jeu.o: main_jeu.c grid_color.h
	${CC} ${CFLAGS}  -c main_jeu.c

jeu_texte: main_jeu.o grid_color.o
	${CC} ${CFLAGS} $^ -o $@ ${LDFLAGS}

clean:
	rm grid_color.o Jeu.o main_jeu.o
