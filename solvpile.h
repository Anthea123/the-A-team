#include <stdbool.h>
#include <stdlib.h>
#include<stdio.h>

typedef struct solvpile solvpile;
solvpile* init_solvpile(void);
bool solvest_vide(solvpile* p);
void solvpush(solvpile** pp, pile* v);
void solvpop(solvpile** pp);
pile* minpile(solvpile* p);
void print_solvpile(solvpile *p);
