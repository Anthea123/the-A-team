/**
*	\file loop_game.h
*	\brief prototypes des fonctions et structures nécessaires pour l'exécution du jeu
*	\author Loubna Anthea Abdellah Bader
*	\version 3.0
*	\date 10 Mars 2017
*/

#ifndef _LOOP_GAME_H
#define _LOOP_GAME_H

#include "grid_color.h"
//#include "solveur.h"
#include "solveur_rapide.h"

/**
*	\fn char get_colour()
*	\brief demande la saisie d'une couleur ou la lettre Q
*	\return le charactère saisi
*/
char get_colour();

/**
*	\fn int get_size()
*	\brief demande la saisie de la taille de la grille
*	\return l'entier saisi
*/
int get_size();

/**
*	\fn int get_nombre_coups()
*	\brief demande la saisie du nombre de coups autorisé
*	\param g la grille qu'on don't on veur savoir le nombre de coups nécessaire pour la résoudre
*	\return l'entier saisi
*/
int get_nombre_coups(grid g);

/**
*	\fn void turn(int *coups_restants, int *nbr_mvm, grid *g, char c)
*	\brief on effectue le changement de couleur dans la grille
*	\param  *coups_restants le pointeur du nombre de coups coups_restants
*	\param  *nbr_mvm le pointeur du nombre de mouvements joués
*	\param  *g le pointeur de la grille
*	\param  c la couleur utilisée
*	\return void 
*/
void turn(int *coups_restants, int *nbr_mvm, grid *g, char c);

/**
*	\fn void check(grid *g, int test_quit, int nbr_mvm)
*	\brief on teste les conditions de victoire ou défaite
*	\param  *g le pointeur de la grille
*	\param  test_quit test qui vaut 1 si le joueur a quité la partie et 0 sinon
*	\param  nbr_mvm nombre de mouvements joués
*	\return void 
*/
void check(grid *g, int test_quit, int nbr_mvm);

/**
*	\fn void game()
*	\brief on exécute toute la boucle de jeu
*	\return void 
*/
void game();

#endif