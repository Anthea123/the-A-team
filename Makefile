

CC=gcc
CFLAGS=-std=c11 -Wall -Wextra -g
LDFLAGS=-lm -lcunit

all: Jeu jeu_texte exsolveur


grid_color.o: grid_color.c grid_color.h
	${CC} ${CFLAGS} -c grid_color.c


SDL.o: SDL.c SDL.h grid_color.h
	${CC} ${CFLAGS} -c SDL.c

Jeu.o: Jeu.c SDL.h grid_color.o
	${CC} ${CFLAGS} -c Jeu.c

Jeu:grid_color.o SDL.o Jeu.o
	${CC} ${CFLAGS} $^ -o $@ ${LDFLAGS} -lSDL -lSDL_ttf

loop_game.o: loop_game.c loop_game.h grid_color.h
	${CC} ${CFLAGS}  -c loop_game.c

main_jeu.o: main_jeu.c grid_color.h loop_game.h
	${CC} ${CFLAGS}  -c main_jeu.c

jeu_texte: main_jeu.o grid_color.o loop_game.o
	${CC} ${CFLAGS} $^ -o $@ ${LDFLAGS}
pile.o:pile.c pile.h
	${CC} ${CFLAGS}  -c pile.c
solvpile.o:solvpile.c solvpile.h pile.h
	${CC} ${CFLAGS}  -c solvpile.c
mainsolveur.o: mainsolveur.c solveur.h  grid_color.h pile.h solvpile.h
	${CC} ${CFLAGS}  -c mainsolveur.c
solveur.o:solveur.c solveur.h grid_color.h pile.h solvpile.h
	${CC} ${CFLAGS}  -c solveur.c
exsolveur:solveur.o mainsolveur.o grid_color.o pile.o solvpile.o
	${CC} ${CFLAGS} $^ -o $@ ${LDFLAGS}
doc: Doxyfile loop_game.h grid_color.h SDL.c
	doxygen Doxyfile

valgrind:
	valgrind --leak-check=yes ./jeu_texte
	valgrind --leak-check=yes ./Jeu
	valgrind --leak-check=yes ./exsolveur

clean:
	rm *.o
