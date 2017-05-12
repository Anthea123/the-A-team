/**
*	\file loop_game.h
*	\brief prototypes des fonctions et structures nécessaires pour l'application Color Flood
*	\author Loubna Anthea Abdellah Bader
*	\version 3.0
*	\date 10 Mai 2017
*/

#ifndef _LOOP_GAME_H
#define _LOOP_GAME_H

#include "grid_color.h"
<<<<<<< HEAD
//#include "solveur.h"
=======
>>>>>>> 49ffadf0a7a80ea154a15e3c849cf98f2060287a
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
*	\brief calcule le nombre de coups autorisés à l'aide du solveur_rapide
*	\param g la grille du jeu
*	\return le nombre de coups autorisés à l'aide du solveur_rapide
*/
int get_nombre_coups(grid g);

/**
*	\fn void turn(int *coups_restants, int *nbr_mvm, grid *g, char c)
*	\brief on effectue le changement de couleur dans la grille
*	\param  *coups_restants le pointeur du nombre de coups coups_restants
*	\param  *nbr_mvm le pointeur du nombre de mouvements joués
*	\param  *g le pointeur de la grille
*	\param  c la couleur utilisée
*	\return void c'est une fonction de type void
*/
void turn(int *coups_restants, int *nbr_mvm, grid *g, char c);

/**
*	\fn void check(grid *g, int test_quit, int nbr_mvm)
*	\brief on teste les conditions de victoire ou défaite
*	\param  *g le pointeur de la grille
*	\param  test_quit test qui vaut 1 si le joueur a quitté la partie et 0 sinon
*	\param  nbr_mvm nombre de mouvements joués
*	\return void 
*/
void check(grid *g, int test_quit, int nbr_mvm);

/**
*	\fn void game()
*	\brief on exécute toute la boucle de jeu
*	\return void c'est une fonction de type void
*/
void game();

#endif
