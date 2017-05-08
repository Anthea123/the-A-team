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
#include "grid_tree.h"
#include "solveur.h"

/***************** tests pour les NArbres *************************/

bool test_egalite(grid g1, grid g2);

void test_nouvelNArbre(void);

void test_ajoutFils(void);

#endif