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
*	\brief tester si la couleur c permet d'avoir une tâche plus grande
*	\param g la grille à résoudre
*	\param c la couleur à tester
*	\return bool true si la couleur c est adjacente à la composante connexe et
	false sinon
*/
bool choixpertinent(grid g,char c);
/**
*	\fn solvpile *solveur(grid g,pile *solution,solvpile* soltrouve, int *iter, int nbcoups)
*	\brief résoudre la grille g
*	\param g la grille à résoudre
*	\param solution une pile contenant une solution de la grille
*	\param *iter pointeur vers le nombre d'itérations au total la fonction 
*	\param nbcoups nombre de coups d'une solution
*	\param soltrouve pile de solutions où on stocke les solutions
*	\return solvpile * adresse d'une pile de solutions
*/
solvpile *solveur(grid g,pile *solution,solvpile* soltrouve, int *iter, int nbcoups);
