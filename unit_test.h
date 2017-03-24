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

/***************** tests pour le solveur ************************/




#endif