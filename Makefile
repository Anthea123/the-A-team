

CC=gcc
CFLAGS=-std=c11 -Wall -Wextra -g
LDFLAGS=-lm -lcunit

all: tests exsolveur solveurSDL jeu


grid_color.o: grid_color.c grid_color.h
	${CC} ${CFLAGS} -c grid_color.c
	
grid_tree.o: grid_tree.c grid_tree.h
	${CC} ${CFLAGS} -c grid_tree.c

SDL.o: SDL.c SDL.h grid_color.h
	${CC} ${CFLAGS} -c SDL.c

solveurSDL.o:solveurSDL.c SDL.h grid_color.o pile.h solvpile.h solveur.h pile.c
	${CC} ${CFLAGS} -c solveurSDL.c

solveurSDL:grid_color.o SDL.o solveurSDL.o pile.o solvpile.o solveur.o
	${CC} ${CFLAGS} $^ -o $@ ${LDFLAGS} -lSDL -lSDL_ttf
	
pile.o:pile.c pile.h
	${CC} ${CFLAGS}  -c pile.c
	
solvpile.o:solvpile.c solvpile.h pile.h
	${CC} ${CFLAGS}  -c solvpile.c

loop_game.o: loop_game.c loop_game.h grid_color.h solveur.h pile.h solvpile.h
	${CC} ${CFLAGS}  -c loop_game.c

main_jeu.o: main_jeu.c loop_game.h solveur.h grid_tree.h
	${CC} ${CFLAGS}  -c main_jeu.c

jeu: main_jeu.o loop_game.o	solveur.o pile.o solvpile.o grid_color.o grid_tree.o
	${CC} ${CFLAGS} $^ -o $@ ${LDFLAGS}
	
mainsolveur.o: mainsolveur.c solveur.h loop_game.h grid_color.h pile.h solvpile.h
	${CC} ${CFLAGS}  -c mainsolveur.c
	
solveur.o:solveur.c solveur.h grid_color.h pile.h solvpile.h
	${CC} ${CFLAGS}  -c solveur.c
	
exsolveur:solveur.o mainsolveur.o grid_color.o pile.o solvpile.o loop_game.o
	${CC} ${CFLAGS} $^ -o $@ ${LDFLAGS}
	
unit_test.o:unit_test.c unit_test.h solveur.h pile.h solvpile.h grid_color.h grid_tree.h
	${CC} ${CFLAGS}  -c unit_test.c
	
main_test.o: main_test.c unit_test.h solveur.h pile.h solvpile.h grid_color.h grid_tree.h
	${CC} ${CFLAGS}  -c main_test.c
	
tests: main_test.o unit_test.o grid_color.o pile.o solvpile.o grid_tree.o solveur.o
	${CC} ${CFLAGS} $^ -o $@ ${LDFLAGS}
	
doc: Doxyfile 
	doxygen Doxyfile

valgrind:
	valgrind --leak-check=yes ./tests
	valgrind --leak-check=yes ./exsolveur
	valgrind --leak-check=yes ./solveurSDL

clean:
	rm *.o
