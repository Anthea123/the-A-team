/**
*	\file pile.h
*	\brief bibliothèque des fonctions des piles
*	\author Loubna Anthea Abdellah Bader
*	\version 3.0
*	\date 2 Apr 2017
*/

#include <stdbool.h>

/**
*	\struct pile
*	\brief structure de pile  de caractères
*/
typedef struct pile pile;

/**
*	\fn pile* init_pile(void)
*	\brief initialiser une pile
*	\param void ne prend pas de paramètres
*	\return pile* adresse d'une ile  
*/
pile* init_pile(void);

/**
*	\fn bool est_vide(pile* p)
*	\brief tester si la pile est vide
*	\param *p adresse d'une pile
*	\return bool true si la pile est vide et false sinon
*/
bool est_vide(pile* p);

/**
*	\fn void push(pile** pp, char c)
*	\brief insérer le caractère c à la tête de la pile pp
*	\param **pp double pointeur sur la pile pp
*	\param c la couleur à insérer
*	\return void c'est une fonction de type void 
*/
void push(pile** pp, char c);

/**
*	\fn void pop(pile** pp)
*	\brief supprimer la tête de la pile pp
*	\param **pp double pointeur sur la pile
*	\return void c'est une fonction de type void  
*/
void pop(pile** pp);

/**
*	\fn char get_head(pile *p)
*	\brief obtenir le caractère à la tête de la pile p
*	\param *p adresse de la pile
*	\return char caractère à la tête de p
*/
char get_head(pile *p);

/**
*	\fn pile * get_next(pile *p)
*	\brief accéder à l'élément suivant de la structure pile
*	\param *p adresse de la pile
*	\return pile* pointeur sur l'élément suivant de la structure pile
*/
pile* get_next(pile *p);

/**
*	\fn int pilelen(pile *p)
*	\brief calculer la longeur de la pile p
*	\param *p adresse de la pile
*	\return int longueur de la pile
*/
int pilelen(pile *p);

/**
*	\fn void print_pile(pile *p)
*	\brief afficher le contenu d'une pile
*	\param *p adresse d'une pile
*	\return void c'est une fonction de type void  
*/
void print_pile(pile *p);

/**
*	\fn void free_pile(pile **pp)
*	\brief libérer la mémoire allouée à la pile pp
*	\param **pp double pointeur sur la pile
*	\return void c'est une fonction de type void 
*/
void free_pile(pile **pp);

/**
*	\fn pile * reverse(pile *p)
*	\brief inverser l'ordre des éléments de la pile p
*	\param *p adresse de la pile
*	\return pile * adresse de la pile renversée
*/
pile * reverse(pile *p);
