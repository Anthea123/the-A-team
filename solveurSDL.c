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
		grid g;int size=2;
		SDL_Surface *ecran = NULL;
		SDL_Event touche;
		initialise();
		TTF_Font *police = NULL;
		police = TTF_OpenFont("LOTB.ttf", 30);
		ecran=SDL_SetVideoMode(600,800, 32, SDL_HWSURFACE|SDL_RESIZABLE);
		SDL_WM_SetCaption("ColorFlood", NULL);
		afficherMenu(ecran,size);
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
									switch(fleche%2){
										case 0 : {
											size++;
											afficherMenu(ecran,size);
											break;
										}
									}
									break;
								}
								case SDLK_LEFT: {
									switch(fleche%2){
										case 0 : {
											if(size>2){
												size--;
											}
											afficherMenu(ecran,size);
											break;
										}
									}
									break;
								}
		 						case SDLK_SPACE: ///Si la touche appuyée est espace
						 		if(fleche%2==1){
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
			jouer(ecran,g,couleuractu);
			SDL_Delay(2000);
			solution=get_next(solution);
		}
		fillScreen(ecran, 255,255,255);
		printgrille(ecran,g);
		finjeu(ecran,police,0,nbr_mvm);
		SDL_Delay(2500);

		free_pile(&solution);
		free_solvpile(&soltrouve);
		free_grid(&g);
		TTF_CloseFont(police);
		TTF_Quit();
		SDL_Quit();
		}

	return 0;
}
