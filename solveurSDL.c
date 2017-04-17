#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include "grid_color.h"
#include "SDL.h"
#include "pile.h"
#include "solvpile.h"
#include "solveur.h"



int main()
{
	while(1)
	{
		grid g;int size=2,nbcoups=1;
		SDL_Rect position;
		SDL_Surface *ecran = NULL,*texte=NULL;
		SDL_Event touche;
		initialise();
		char mouvement[100];
		TTF_Font *police = NULL;
		police = TTF_OpenFont("LOTB.ttf", 30);
		SDL_Color couleurNoire,couleurBlanche;couleurNoire.r=255; couleurNoire.g=255;couleurNoire.b=255;couleurBlanche.r=0; couleurBlanche.g=0;couleurBlanche.b=0;
		ecran=SDL_SetVideoMode(600,800, 32, SDL_HWSURFACE|SDL_RESIZABLE);
		SDL_WM_SetCaption("ColorFlood", NULL);
		afficherMenu(ecran,size,nbcoups);
		drawRectangle(ecran,10,300,10,0,0,0);
		SDL_Flip(ecran);
		int compteur=1,fleche=300;
			//MENU//
   		while(compteur)
		{
			SDL_WaitEvent(&touche);
			{switch(touche.type)
				{
				 	case SDL_QUIT: return 0;
				 	case SDL_KEYDOWN: ///Si une touche à été appuyée
						 switch(touche.key.keysym.sym){
					 			case SDLK_DOWN: {
									 fleche++;
									 dessinerfleche(ecran,fleche);
									 break;
								}
								case SDLK_UP: {
									fleche--;
									dessinerfleche(ecran,fleche);
									break;
								}
								case SDLK_RIGHT: {
									switch(fleche%3){
										case 0 : {
											size++;
											afficherMenu(ecran,size,nbcoups);
											break;
										}
										case 1 : {
											nbcoups++;
											afficherMenu(ecran,size,nbcoups);
											break;
										}
									}
									break;
								}
								case SDLK_LEFT: {
									switch(fleche%3){
										case 0 : {
											if(size>2){
												size--;
											}
											afficherMenu(ecran,size,nbcoups);
											break;
										}
										case 1 : {
											if(nbcoups>1){
												nbcoups--;
											}
											afficherMenu(ecran,size,nbcoups);
											break;
										}
									}
									break;
								}
		 						case SDLK_SPACE: ///Si la touche appuyée est espace
						 		if(fleche%3==2){
									 return 0;
								}
								else compteur=0;
								break;
				 				case SDLK_ESCAPE: /* Appui sur la touche Echap, on arrête le programme */return 0;
				 				default : ;
							}
					default : ;
				}
	   		}
  		}
	 	fillScreen(ecran, 255,255,255);
		g=init_grid(size);printgrille(ecran,g);
		int cinit=nbcoups;
		sprintf(mouvement,"%d/%d",nbcoups,cinit);
		texte = TTF_RenderText_Shaded(police, mouvement,couleurBlanche,couleurNoire);
		position.x = 10;
		position.y = 10;
		SDL_BlitSurface(texte, NULL, ecran,&position);
		SDL_Flip(ecran);

		pile *solution=NULL;
		solvpile *soltrouve=NULL;
		int iter=0;
		soltrouve=solveur(g,solution,soltrouve,&iter,0);
		solution=reverse(minpile(soltrouve));
		int nbr_mvm=pilelen(solution);
		while(solution!=NULL){
			char couleuractu=get_head(solution);
			drawRectangle(ecran,10,10,80,255,255,255);
			drawRectangle(ecran,120,10,90,255,255,255);
			sprintf(mouvement,"%d/%d",nbcoups,cinit);
			texte = TTF_RenderText_Shaded(police, mouvement,couleurBlanche,couleurNoire);
			SDL_BlitSurface(texte, NULL, ecran,&position);
			jouer(ecran,g,couleuractu);
			SDL_Delay(2000);
			nbcoups--;
			if(nbcoups<0 && !test_same_colour(&g)){
				fillScreen(ecran, 255,255,255);
				printgrille(ecran,g);finjeu(ecran,police,1,nbr_mvm-1);
				SDL_Delay(2500);
				break;
			}
			solution=get_next(solution);
		}
		if(test_same_colour(&g)) {
			fillScreen(ecran, 255,255,255);
			printgrille(ecran,g);
			finjeu(ecran,police,0,nbr_mvm-1);
			SDL_Delay(2500);
		}
		free_pile(&solution);
		free_solvpile(&soltrouve);
		free_grid(&g);	
		TTF_CloseFont(police);
		TTF_Quit();
		SDL_Quit();
		}

	return 0;
}
