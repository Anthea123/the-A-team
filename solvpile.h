/**
*	\file solvpile.h
*	\brief bibliothèque contenant les fonctions pour les piles de solutions
*	\author Loubna Anthea Abdellah Bader
*	\version 3.0
*	\date 2 Apr 2017
*/
#include <stdbool.h>
#include <stdlib.h>
#include<stdio.h>
#include "pile.h"
/**
*	\struct solvpile
*	\brief structure de pile de pile pour stocker les piles de solutions
*/
typedef struct solvpile solvpile;
/**
*	\fn solvpile* init_solvpile(void)
*	\brief initialiser les piles de piles
*	\param void ne prend pas de paramètres
*	\return solvpile* adresse d'une solvpile  
*/
solvpile* init_solvpile(void);
/**
*	\fn bool solvest_vide(solvpile* p)
*	\brief tester si la pile de solutions est vide
*	\param *p adresse d'une solvpile
*	\return bool true si la solvpile est vide et false sinon
*/
bool solvest_vide(solvpile* p);
/**
*	\fn void solvpush(solvpile** pp, pile* v)
*	\brief insérer l'adresse de la pile v à la tête de la pile pp
*	\param **pp double pointeur sur la pile de solutions pp 
*	\param *v l'adresse de la pile à insérer
*	\return void c'est une fonction de type void 
*/
void solvpush(solvpile** pp, pile* v);
/**
*	\fn void solvpop(solvpile** pp)
*	\brief supprimer la tête de la pile de solutions pp
*	\param **pp double pointeur sur la pile de solutions
*	\return void c'est une fonction de type void  
*/
void solvpop(solvpile** pp);
/**
*	\fn pile* minpile(solvpile* p)
*	\brief trouver la pile de longeur minimale parmi les piles dans la solvpile
*	\param *p adresse d'une solvpile
*	\return pile* pointeur sur la pile minimale
*/
pile* minpile(solvpile* p);
/**
*	\fn void print_solvpile(solvpile *p)
*	\brief afficher les contenus d'une pile de solutions
*	\param *p adresse d'une solvpile
*	\return void c'est une fonction de type void  
*/
void print_solvpile(solvpile *p);
/**
*	\fn void free_solvpile(solvpile **pp)
*	\brief libérer la mémoire allouée à la solvpile pp
*	\param **pp double pointeur sur la solvpile
*	\return void c'est une fonction de type void 
*/
void free_solvpile(solvpile **pp);

/**
*	\fn pile * solvget_head(solvpile *pp)
*	\brief obtenir un pointeur sur la pile à la tête de la pile de solutions pp
*	\param **pp double pointeur sur la solvpile
*	\return pile* pointeur sur la pile à la tête de pp
*/
pile * solvget_head(solvpile *pp);

/**
*	\fn solvpile * solvget_next(solvpile *pp)
*	\brief accéder à l'élément suivant de la structure solvpile
*	\param **pp double pointeur sur la solvpile
*	\return solvpile* pointeur sur l'élément suivant de la structure solvpile
*/
solvpile * solvget_next(solvpile *pp);
