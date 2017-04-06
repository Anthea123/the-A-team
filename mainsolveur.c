#include<stdio.h>
#include<stdlib.h>
#include "solveur.h"
#include "grid_color.h"
#include "pile.h"
#include "solvpile.h"
#include "loop_game.h"

void game2(grid *g, pile *p){
	int coups_restants;
	int nbr_mvm = 0;

    coups_restants = pilelen(p);

	detect_flood(g, 0, 0, g->array[0][0]);
		
	while(!test_same_colour(g) && coups_restants > 0 ){
		turn(&coups_restants, &nbr_mvm, g, get_head(p));
		pop(&p);
	}
		
	if(test_same_colour(g)){
		printf("Victoire\n");
	}
}

int main(int argc, char *argv[]){
	if(argc != 2){
		perror("arguments");
		exit(1);
	}

	grid g1=init_grid(atoi(argv[1]));
	printf("Grille qu'on veut résoudre:\n");
	grid_print(&g1);
	printf("\n");
	pile *solution=NULL;
	solvpile *soltrouve=NULL;

	soltrouve=solveur(g1,solution,0,1,soltrouve);
	pile * p = reverse(minpile(soltrouve));

	printf("Solution:\n");
	print_pile(p);
	printf("\n");

	game2(&g1, p);

	free_pile(&solution);
	free_solvpile(&soltrouve);
	free_grid(&g1);	
}
