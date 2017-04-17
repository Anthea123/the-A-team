/**
*	\file solveur.c
*	\brief implémentation des fonctions du solveur
*	\author Loubna Anthea Abdellah Bader
*	\version 3.0
*	\date 2 Apr 2017
*/
#include <stdbool.h>
#include <stdlib.h>
#include "grid_color.h"
#include "solveur.h"
#include "pile.h"
#include "solvpile.h"


char couleurs[6]={'B','V','R','J','M','G'};

grid copy(grid g)
{
	int n=g.size;
	grid g1=init_grid(g.size);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
					g1.array[i][j]=g.array[i][j];
					g1.belong[i][j]=g.belong[i][j];
		}
	}
	return g1;
}

bool choixpertinent(grid g,char c)
{
	if(g.array[0][0]==c)
		return false;

	int n=g.size;
	detect_flood(&g,0,0,g.array[0][0]);
	grid g1=copy(g);
	detect_flood(&g1,0,0,g1.array[0][0]);
	change_color(&g1,c);
	refresh_grid(&g1);
	detect_flood(&g1,0,0,g1.array[0][0]);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(g1.belong[i][j]!=g.belong[i][j]){
				free_grid(&g1);
				return true;
				}
		}
	}

	free_grid(&g1);
	return false;
}

solvpile* solveur(grid g,pile *solution,solvpile* soltrouve, int *iter, int nbcoups){
	if(*iter > 1000000){
		//printf("iter: %d\n", *iter);
		return soltrouve;
	}
	if(g.size <= 1){
		printf("taille non valide\n");
		push(&solution, g.array[0][0]);
		solvpush(&soltrouve, solution);
		return soltrouve;
	}
	*iter = *iter+1;
	for(int i=0;i<6;i++){
		if(choixpertinent(g,couleurs[i]) ){
			grid g2=copy(g);
			push(&solution,couleurs[i]);
			detect_flood(&g2,0,0,g.array[0][0]);
			change_color(&g2,couleurs[i]);
			refresh_grid(&g2);
			if(test_same_colour(&g2)){
				if(nbcoups> pilelen(solution) || solvest_vide(soltrouve))
				{solvpush(&soltrouve,solution);
				nbcoups = pilelen(solvget_head(soltrouve));
				printf("Solution en %d coups:\n", nbcoups);
				print_pile(solution);
				solution=NULL;
				}
			}
			else{
				soltrouve=solveur(g2,solution,soltrouve, iter, nbcoups);
			}
			free_grid(&g2);
		}
	}
	return soltrouve;
}
