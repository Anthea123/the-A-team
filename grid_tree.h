/**
*	\file grid_tree.h
*	\brief prototypes des fonctions et structures des arbres de grilles
*	\author Loubna Anthea Abdellah Bader
*	\version 1.0
*	\date 1 Mai 2017
*/
#ifndef _GRID_TREE_H
#define _GRID_TREE_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>
#include"grid_color.h"

/**
*	\struct g_narbre NNoeud, *NArbre
*	\brief arbre n-aire de grilles
*/
typedef struct g_narbre NNoeud, *NArbre;
/**
*	\fn NArbre nouvelNArbre(grid g)
*	\brief création d'un arbre n-aire de grilles intialisées à NULL
*	\param g grille racine à partir de laquelle on crée l'arbre
*	\return NArbre arbre n-aire de grilles 
*/
NArbre nouvelNArbre(grid g);
/**
*	\fn NArbre ajoutFils(NArbre a, NArbre fils)
*	\brief ajouter une grille fille à l'arbre n-aire de grilles
*	\param g la grille racine
*	\param a la grille fille à rajouter à l'arbre
*	\return NArbre arbre n-aire de grilles auquel a été rajouté la grille fils
*/
NArbre ajoutFils(NArbre a, NArbre fils);
/**
*	\fn void print_grid_tree(NArbre g)
*	\brief afficher un arbre de grilles 
*	\param g la grille racine
*	\return void fonction d'affichage
*/
void print_grid_tree(NArbre g);
#endif


