

CC=gcc
CFLAGS=-std=c11 -Wall -Wextra -g
LDFLAGS=-lm -lcunit

all: tests exsolveur solveurSDL


grid_color.o: grid_color.c grid_color.h
	${CC} ${CFLAGS} -c grid_color.c

SDL.o: SDL.c SDL.h grid_color.h  solveur_rapide.h
	${CC} ${CFLAGS} -c SDL.c

solveurSDL.o:solveurSDL.c SDL.h grid_color.o  solveur_rapide.h
	${CC} ${CFLAGS} -c solveurSDL.c

solveurSDL:grid_color.o SDL.o solveurSDL.o  solveur_rapide.o
	${CC} ${CFLAGS} $^ -o $@ ${LDFLAGS} -lSDL -lSDL_ttf  -lSDL_gfx -lSDL_mixer

pile.o:pile.c pile.h
	${CC} ${CFLAGS}  -c pile.c

solvpile.o:solvpile.c solvpile.h pile.h
	${CC} ${CFLAGS}  -c solvpile.c

loop_game.o: loop_game.c loop_game.h grid_color.h
	${CC} ${CFLAGS}  -c loop_game.c

mainsolveur.o: mainsolveur.c solveur.h loop_game.h grid_color.h pile.h solvpile.h
	${CC} ${CFLAGS}  -c mainsolveur.c

solveur.o:solveur.c solveur.h grid_color.h pile.h solvpile.h
	${CC} ${CFLAGS}  -c solveur.c

exsolveur:solveur.o mainsolveur.o grid_color.o pile.o solvpile.o loop_game.o
	${CC} ${CFLAGS} $^ -o $@ ${LDFLAGS}

unit_test.o:unit_test.c unit_test.h solveur.h pile.h solvpile.h grid_color.h
	${CC} ${CFLAGS}  -c unit_test.c

main_test.o: main_test.c unit_test.h solveur.h pile.h solvpile.h grid_color.h
	${CC} ${CFLAGS}  -c main_test.c

tests: main_test.o unit_test.o grid_color.o pile.o solvpile.o solveur.o
	${CC} ${CFLAGS} $^ -o $@ ${LDFLAGS}

doc: Doxyfile
	doxygen Doxyfile

valgrind:
	valgrind --leak-check=yes ./tests
	valgrind --leak-check=yes ./exsolveur
	valgrind --leak-check=yes ./solveurSDL

clean:
	rm *.o
