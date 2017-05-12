

#include <stdbool.h>
#include <stdlib.h>
#include "grid_color.h"

void solution_rapide(grid grille_depart, char sol[100], int *i);

grid copy(grid g);

bool choixpertinent(grid g,char c);

int compteur(grid g);

char size_tache(grid g, char couleurs[6]);