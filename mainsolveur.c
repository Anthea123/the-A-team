#include<stdio.h>
#include<stdlib.h>
#include "solveur.h"
#include "grid_color.h"
#include "pile.h"
#include "solvpile.h"

int main(){
	grid g1=init_grid(3);
	grid_print(&g1);
	printf("\n");
	pile *solution=NULL;
	solvpile *soltrouve=NULL;
	soltrouve=solveur(g1,solution,0,1,soltrouve);
	print_pile(minpile(soltrouve));

	free_pile(&solution);
	free_solvpile(&soltrouve);
	free_grid(&g1);	
}
