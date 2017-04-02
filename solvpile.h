/**
*	\file solpile.h
*	\brief bibliothèque 
*	\author Loubna Anthea Abdellah Bader
*	\version 3.0
*	\date 2 Apr 2017
*/
#include <stdbool.h>
#include <stdlib.h>
#include<stdio.h>
/**
*	\struct 
*	\brief 
*/
typedef struct solvpile solvpile;
/**
*	\fn solvpile* init_solvpile(void)
*	\brief 
*	\param void ne prend pas de paramètres
*	\return gridsolvpile* adresse d'une solvpile  
*/
solvpile* init_solvpile(void);
/**
*	\fn bool solvest_vide(solvpile* p)
*	\brief 
*	\param *p adresse d'une solvpile
*	\return bool  
*/
bool solvest_vide(solvpile* p);
/**
*	\fn void solvpush(solvpile** pp, pile* v)
*	\brief 
*	\param *pp la grille à copier
*	\param *v la grille à copier
*	\return void c'est une fonction de type void 
*/
void solvpush(solvpile** pp, pile* v);
/**
*	\fn void solvpop(solvpile** pp)
*	\brief 
*	\param **pp 
*	\return void c'est une fonction de type void  
*/
void solvpop(solvpile** pp);
/**
*	\fn pile* minpile(solvpile* p)
*	\brief 
*	\param *p adresse d'une solvpile
*	\return pile* pointeur sur une pile 
*/
pile* minpile(solvpile* p);
/**
*	\fn void print_solvpile(solvpile *p)
*	\brief 
*	\param *p adresse d'une solvpile
*	\return void c'est une fonction de type void  
*/
void print_solvpile(solvpile *p);
/**
*	\fn void free_solvpile(solvpile **pp)
*	\brief 
*	\param **pp 
*	\return void c'est une fonction de type void 
*/
void free_solvpile(solvpile **pp);
/**
*	\fn pile * solvget_head(solvpile *pp)
*	\brief 
*	\param **pp
*	\return pile* pointeur sur une pile
*/
pile * solvget_head(solvpile *pp);
/**
*	\fn solvpile * solvget_next(solvpile *pp)
*	\brief 
*	\param *pp
*	\return solvpile * pointeur sur une solvpile 
*/
solvpile * solvget_next(solvpile *pp);
