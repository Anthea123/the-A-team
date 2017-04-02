/**
*	\file solveur.h
*	\brief bibliothèque des fonctions du solveur
*	\author Loubna Anthea Abdellah Bader
*	\version 3.0
*	\date 2 Apr 2017
*/
#include <stdbool.h>
#include "grid_color.h"
#include "pile.h"
#include "solvpile.h"
/**
*	\fn grid copy(grid g)
*	\brief fait la copie de la grille g dans une autre grille g1 retournée
*	\param g la grille à copier
*	\return grid une copie de la grille d'origine g 
*/
grid copy(grid g);
/**
*	\fn bool choixpertinent(grid g,char c)
*	\brief 
*	\param g la grille à copier
*	\return bool  
*/
bool choixpertinent(grid g,char c);
/**
*	\fn solvpile *solveur(grid g,pile *solution,int prof,int profmax,solvpile* soltrouve)
*	\brief 
*	\param g la grille
*	\param solution 
*	\param prof 
*	\param profmax 
*	\param soltrouve 
*	\return solvpile *
*/
solvpile *solveur(grid g,pile *solution,int prof,int profmax,solvpile* soltrouve);
