#ifndef SDL_H
#define SDL_H

#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include "grid_color.h"
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>

/**
*	\fn drawRectangle(SDL_Surface *ecran, int px, int py, int size, int r, int g, int b)
*	\brief permet de tracer un rectangle sur l'ecran dans les coordonnes (px,py) d'un taille de size avec le systeme de couleurs {RGB}
*	\param *ecran adresse de l'ecran
*	\param px abscisse de l'origine du rectangle
*	\param py ordonnée de l'origine du rectangle
*	\param size taille du rectangle
*	\param r,g,b la couleur du rectangle
*	\return void c'est une fonction de type void
*/
void drawRectangle(SDL_Surface *ecran, int px, int py, int size, int r, int g, int b);
/**
*	\fn fillScreen(SDL_Surface *ecran, int r, int g, int b)
*	\brief permet de remplisser entierement une surface sdl par une couleur RGB
*	\param *ecran adresse de l'ecran
*	\param r,g,b la couleur du surface
*	\return void c'est une fonction de type void
*/
void fillScreen(SDL_Surface *ecran, int r, int g, int b);
/**
*	\fn void printgrille(SDL_Surface *ecran,grid g)
*	\brief permet de tracer la grille a partir d'une grille initialisée par les chaines de  caractere correspondants aux couleurs
*	\param *ecran adresse de l'ecran
*	\param g grille
*	\return void c'est une fonction de type void
*/
void printgrille(SDL_Surface *ecran,grid g);
/**
*	\fn printcouleurs(SDL_Surface *ecran)
*	\brief permet de tracer l'interface des 6 couleurs qui serait fixe tout au long du jeu et permette au l'utilisateur de choisir la couleur parmi elles
*	\param *ecran adresse de l'ecran
*	\param g grille
*	\return void c'est une fonction de type void
*/
void printcouleurs(SDL_Surface *ecran);
/**
*	\fn jouer(SDL_Surface *ecran,grid g,char c)
*	\brief permet de changer la couleur de la grille a chaque fois qu'on joue une couleur parmi les 7 a partir d'un caractere de la grille g
*	\param *ecran adresse de l'ecran
*	\param g grille
*	\param char c la couleur joue
*	\return void c'est une fonction de type void
*/
void jouer(SDL_Surface *ecran,grid g,char c);
/**
*	\fn  afficherMenu(SDL_Surface *ecran,int size,int nbcoups)
*	\brief permet d'afficher le menu constitue du choix de la taille et le nombre de coups autorsisees et une option de QUIT
*	\param *ecran adresse de l'ecran
*	\param g grille
*	\param size taille que l'utilisateur veut choisir pour la grille
*	\param nbcoups le nombre de coups que l'utilisateuer veut choisir pour la grille
*	\return void c'est une fonction de type void
*/
void afficherMenu(SDL_Surface *ecran,int size,int nbcoups);

/**
*	\fn void initialise()
*	\brief permet d'initialiser video responsable pour l'interface graphique et TTF responsable des polices(ecriture)
*	\return void c'est une fonction de type void
*/
void initialise();
/**
*	\fn dessinerfleche(SDL_Surface *ecran,int fleche)
*	\brief permet d'afficher le fleche pour surfer dans le menu et choisir les options de jeu en s'appyant sur un entier fleche
*	\param *ecran adresse de l'ecran
*	\param fleche pour de marquer l'emlacement du fleche au cours de navigation menu
*	\return void c'est une fonction de type void
*/
void dessinerfleche(SDL_Surface *ecran,int fleche);
/**
*	\fn finjeu(SDL_Surface *ecran,TTF_Font *police,int WL,int nbr_mvm)
*	\brief permet d'afficher les messages de fin de jeu(win or lose) et afficher la grille dans son etat final ainsi le nombre de mouvements faites pour ganger
*	\param *ecran adresse de l'ecran
*	\param plice pour ecrire les message
*	\param WL pour designer (win or lose )
*	\param nbr_mvm le nombre de mouvements pour gagner la partie 
*	\return void c'est une fonction de type void
*/
int finjeu(SDL_Surface *ecran,TTF_Font *police,int WL,int nbr_mvm);

#endif
