#ifndef SDL_H
#define SDL_H

#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include "grid_color.h"
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>

void drawRectangle(SDL_Surface *ecran, int px, int py, int size, int r, int g, int b);
void fillScreen(SDL_Surface *ecran, int r, int g, int b);
void printgrille(SDL_Surface *ecran,grid g);
void printcouleurs(SDL_Surface *ecran);
void jouer(SDL_Surface *ecran,grid g,char c);
void afficherMenu(SDL_Surface *ecran,int size,int nbcoups);
void initialise();
void dessinerfleche(SDL_Surface *ecran,int fleche);
int finjeu(SDL_Surface *ecran,TTF_Font *police,int WL,int nbr_mvm);

#endif
