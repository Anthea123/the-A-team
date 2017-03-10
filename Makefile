

CC=gcc
CFLAGS=-std=c11 -Wall -Wextra -g
LDFLAGS=-lm -lcunit

all: jeu_SDL jeu_texte

grid_color.o: grid_color.c grid_color.h
	${CC} ${CFLAGS} -c grid_color.c

loop_SDL.o: loop_SDL.c loop_SDL.h grid_color.h
	${CC} ${CFLAGS} -c loop_SDL.c

Jeu.o: Jeu.c loop_SDL.h grid_color.h
	${CC} ${CFLAGS} -c Jeu.c

jeu_SDL: Jeu.o loop_SDL.o grid_color.o
	${CC} ${CFLAGS} $^ -o $@ ${LDFLAGS} -lSDL -lSDL_ttf

main_jeu.o: main_jeu.c grid_color.h
	${CC} ${CFLAGS} -c main_jeu.c

jeu_texte: main_jeu.o loop_game.o grid_color.o
	${CC} ${CFLAGS} $^ -o $@ ${LDFLAGS}

loop_game.o: loop_game.c loop_game.h grid_color.h
	${CC} ${CFLAGS} -c loop_game.c

doc: Doxyfile loop_game.h loop_SDL.h grid_color.h
	doxygen Doxyfile

valgrind: valgrind --leak-check=yes ./jeu_texte

clean:
	rm *.o
