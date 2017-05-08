
/**
*	\file grid_tree.c
*	\brief bibliothèque des arbres de grilles
*	\author Loubna Anthea Abdellah Bader
*	\version 1.0
*	\date 1 Mai 2017
*/
#include "grid_tree.h"
#define MAXFILS 5
#define ARBREVIDE NULL

typedef struct g_narbre 
{
	grid g;
	struct g_narbre *tabfils[MAXFILS]; // tableau des fils, initialisés à NULL
	int nbFils; // nombre de fils, doit être initialisé à 0.
	
} NNoeud, *NArbre;

NArbre nouvelNArbre(grid g) 
{
	NArbre res=NULL;
	int i;
	res = (NArbre)malloc(sizeof(NNoeud));
	res -> g = g;
	res -> nbFils = 0;
	for(i=0;i<MAXFILS;i=i+1){
		res->tabfils[i] = ARBREVIDE;
	}
	return res;
}

void ajoutFils(NArbre a, NArbre fils) 
{
	
	if (a!=ARBREVIDE) 
	{
		if (a->nbFils < MAXFILS) 
		{
			a->tabfils[a->nbFils]=fils;
			a->nbFils++;
		}
	}
	
}

int getnbFils(NArbre a){
	return a->nbFils;
}

grid getgrid(NArbre a){
	return a->g;
}

void print_grid_tree(NArbre g)
{
	if(g == ARBREVIDE){
		printf("arbre vide");
	}
	else{
		int i;
		grid_print(&g->g);

		for(i=0;i<g->nbFils;i=i+1)
		{
			//printf("fils %d\n", i);
			print_grid_tree(g->tabfils[i]);
		}
	}
}

void free_grid_tree(NArbre g)
{
	if (g != ARBREVIDE){
		free_grid(&g->g);
		for(int i = 0; i < g->nbFils; i = i+1){
			//printf("fils %d\n", i);
			free_grid_tree(g->tabfils[i]);
		}
		//free(&g->tabfils);
 		free(g);
	}
}
