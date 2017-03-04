

CC=gcc
CFLAGS=-std=c11 -Wall -Wextra -g
LDFLAGS=-lm -lcunit

all: exSDL

#unit_test.o : unit_test.c unit_test.h struct.h
#	${CC} ${CFLAGS} -c unit_test.c

grid_color.o: grid_color.c grid_color.h
	${CC} ${CFLAGS} -c grid_color.c

exSDL.o: exSDL.c SDLMain.h
	${CC} ${CFLAGS} -c exSDL.c

exSDL: grid_color.o exSDL.o #unit_test.o
	${CC} ${CFLAGS} $^ -o $@ ${LDFLAGS} -lSDL -lSDL_ttf


clean:
	rm grid_color.o main.o
