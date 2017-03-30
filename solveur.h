#include <stdbool.h>
#include "grid_color.h"
#include "pile.h"
#include "solvpile.h"
grid copy(grid g);
bool choixpertinent(grid g,char c);
solvpile *solveur(grid g,pile *solution,int prof,int profmax,solvpile* soltrouve);
