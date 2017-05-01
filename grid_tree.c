
/**
*	\file grid_tree.c
*	\brief bibliothèque des arbres de grilles
*	\author Loubna Anthea Abdellah Bader
*	\version 1.0
*	\date 1 Mai 2017
*/
#include "grid_tree.h"
#define MAXFILS 10
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
    for(i=0;i<MAXFILS;i=i+1)
        res->tabfils[i]=ARBREVIDE;
    return res;
}

NArbre ajoutFils(NArbre a, NArbre fils) 
{
    NArbre res=a;
    if (a!=ARBREVIDE) 
    {
        if (a->nbFils < MAXFILS) 
        {
            a->tabfils[a->nbFils]=fils;
            a->nbFils++;
        }
    }
    return res;
}
void print_grid_tree(NArbre g)
{
   // int i;
    grid_print(&g->g);

   /* for(i=0;i<MAXFILS;i=i+1)
    {
        print_grid_tree(g->tabfils[i]);
    }*/
}
