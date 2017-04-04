#ifndef _UNIT_TEST_H
#define _UNIT_TEST_H

/**
*	\file unit_test.h
*	\brief prototypes des fonctions et structures nécessaires pour les tests unitaires des fonctions contenues dans pile.c et solveur.c
*	\author Loubna Anthea Abdellah Bader
*	\version 1.0
*	\date 24 Mar 2017
*/

#include <stdbool.h>
#include "CUnit/CUnit.h"
#include "CUnit/Basic.h"
#include "grid_color.h"
#include "solvpile.h"
#include "pile.h"
#include "solveur.h"

/***************** tests pour les piles *************************/


/**
*	 \fn test_init_pile(void)
*	 \brief test unitaire de la fonction init_pile
*	 \param  void aucun
*	 \return void fonction de type void
*/
void test_init_pile(void);

/**
*	 \fn test_est_vide(void)
*	 \brief test unitaire de la fonction est_vide
*	 \param  void aucun
*	 \return void fonction de type void
*/
void test_est_vide(void);

/**
*	 \fn test_push(void)
*	 \brief test unitaire de la fonction push
*	 \param  void aucun
*	 \return void fonction de type void
*/
void test_push(void);

/**
*	 \fn test_pop(void)
*	 \brief test unitaire de la fonction pop
*	 \param  void aucun
*	 \return void fonction de type void
*/
void test_pop(void);

/**
*	 \fn test_free_pile(void)
*	 \brief test unitaire de la fonction free_pile
*	 \param  void aucun
*	 \return void fonction de type void
*/
void test_free_pile(void);

/**
*	 \fn test_get_head(void)
*	 \brief test unitaire de la fonction get_head
*	 \param  void aucun
*	 \return void fonction de type void
*/
void test_get_head(void);

/**
*	 \fn test_get_next(void)
*	 \brief test unitaire de la fonction get_next
*	 \param  void aucun
*	 \return void fonction de type void
*/
void test_get_next(void);


/**
*	 \fn test_pilelen(void)
*	 \brief test unitaire de la fonction pilelen
*	 \param  void aucun
*	 \return void fonction de type void
*/
void test_pilelen(void);


/******************tests pour les piles de piles*****************/

/**
*	 \fn test_init_solvpile(void)
*	 \brief test unitaire de la fonction init_solvpile
*	 \param  void aucun
*	 \return void fonction de type void
*/
void test_init_solvpile(void);

/**
*	 \fn test_solvest_vide(void)
*	 \brief test unitaire de la fonction solvest_vide
*	 \param  void aucun
*	 \return void fonction de type void
*/
void test_solvest_vide(void);

/**
*	 \fn compare_piles(pile *p1, pile *p2)
*	 \brief teste si les piles passées en paramètres contiennent les mêmes caractères dans le même ordre
*	 \param  *p1 pointeur vers une pile
*	 \param  *p2 pointeur vers une pile
*	 \return true si les piles contiennent les mêmes éléments
*    \return false sinon
*/
bool compare_piles(pile *p1, pile *p2);

/**
*	 \fn test_solvpush(void)
*	 \brief test unitaire de la fonction solvpush
*	 \param  void aucun
*	 \return void fonction de type void
*/
void test_solvpush(void);

/**
*	 \fn test_solvpop(void)
*	 \brief test unitaire de la fonction solvpop
*	 \param  void aucun
*	 \return void fonction de type void
*/
void test_solvpop(void);

/**
*	 \fn test_free_solvpile(void)
*	 \brief test unitaire de la fonction free_solvpile
*	 \param  void aucun
*	 \return void fonction de type void
*/
void test_free_solvpile(void);

/**
*	 \fn test_free_solvget_head(void)
*	 \brief test unitaire de la fonction free_solvget_head
*	 \param  void aucun
*	 \return void fonction de type void
*/
void test_solvget_head(void);

/**
*	 \fn test_free_solvget_next(void)
*	 \brief test unitaire de la fonction free_solvget_next
*	 \param  void aucun
*	 \return void fonction de type void
*/
void test_solvget_next(void);

/**
*	 \fn test_minpile(void)
*	 \brief test unitaire de la fonction free_minpile
*	 \param  void aucun
*	 \return void fonction de type void
*/
void test_minpile(void);

/***************** tests pour le solveur ************************/

/**
*	 \fn test_egalite(grid g1, grid g2);
*	 \brief teste si les grilles passées en paramètre sont égales
*	 \param g1 une grille
*	 \param g2 une grille 
*	 \return true si les tableaux array et les tableaux belong des grilles contiennent les mêmes informations
*    \return false sinon
*/
bool test_egalite(grid g1, grid g2);

/**
*	 \fn test_copy(void)
*	 \brief test unitaire de la fonction copy
*	 \param  void aucun
*	 \return void fonction de type void
*/
void test_copy(void);


#endif