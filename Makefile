

CC=gcc
CFLAGS=-std=c11 -Wall -Wextra -g
LDFLAGS=-lm -lcunit

all: exSDL

unit_test.o : unit_test.c unit_test.h struct.h
	${CC} ${CFLAGS} -c unit_test.c

struct.o: struct.c struct.h
	${CC} ${CFLAGS} -c struct.c

exSDL.o: exSDL.c SDLMain.h
	${CC} ${CFLAGS} -c exSDL.c

exSDL: struct.o exSDL.o unit_test.o
	${CC} ${CFLAGS} $^ -o $@ ${LDFLAGS} -lSDL


clean:
	rm struct.o main.o
