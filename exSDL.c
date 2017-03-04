#include "struct.h"
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>

/*
 compilation soous Linux : gcc -o exSDL exSDL.c -lSDL
 compilation sur Mac : gcc -o exSDL -I/Library/Frameworks/SDL.framework/Headers  exSDL.c SDLmain.m -framework SDL -framework Cocoa
*/

int autoDraw=0;

// px, py coordonnées haut, gauche de la texture
void drawTexture(SDL_Surface *ecran, int px, int py, SDL_Surface *ima) {
	SDL_Rect rect;
    rect.x=px;
    rect.y=py;
	SDL_BlitSurface(ima, NULL, ecran, &rect);
	SDL_Flip(ecran);
}

// px, py coordonnées haut, gauche du pixel
void drawRectangle(SDL_Surface *ecran, int px, int py, int size, int r, int g, int b) {
    SDL_Rect rect;
    rect.x=px;
    rect.y=py;
    rect.h=rect.w=size;
    SDL_FillRect(ecran, &rect, SDL_MapRGB(ecran->format, r, g, b));
    SDL_Flip(ecran);
}

// px, py coordonnées haut, gauche du pixel
void drawPixel(SDL_Surface *ecran, int px, int py, int r, int g, int b) {
    drawRectangle(ecran,  px,  py, 1,  r,  g,  b);
}

void fillScreen(SDL_Surface *ecran, int r, int g, int b) {
    SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, r, g, b));
    SDL_Flip(ecran);
}

void printgrille(SDL_Surface *ecran,grid g){
		int size=g.size;
		int sizerectan=600/size;
		for(int i=0;i<size;i++){
			for(int j=0;j<size;j++){
				switch (g.array[j][i]) {
					case 'V':
								drawRectangle(ecran,i*sizerectan,j*sizerectan,sizerectan,0,255,0);break;
					case 'R':
								drawRectangle(ecran,i*sizerectan,j*sizerectan,sizerectan,255,0,0);break;
					case 'B':
								drawRectangle(ecran,i*sizerectan,j*sizerectan,sizerectan,0,0,255);break;
					case 'J':
								drawRectangle(ecran,i*sizerectan,j*sizerectan,sizerectan,255,255,0);break;
					case 'M':
								drawRectangle(ecran,i*sizerectan,j*sizerectan,sizerectan,114,89,63);break;
					case 'G':
								drawRectangle(ecran,i*sizerectan,j*sizerectan,sizerectan,127,127,127);break;
					default:
									;
				}
			}
		}

}

void printcouleurs(SDL_Surface *ecran){
		drawRectangle(ecran,0,610,100,0,255,0);
		drawRectangle(ecran,100,610,100,255,0,0);
		drawRectangle(ecran,200,610,100,0,0,255);
		drawRectangle(ecran,300,610,100,255,255,0);
		drawRectangle(ecran,400,610,100,114,89,63);
		drawRectangle(ecran,500,610,100,127,127,127);
}

void jouer(SDL_Surface *ecran,grid g,char c){
	identiftache(g,0,0,g.array[0][0]);
	changecolor(g,c);
	printgrille(ecran,g);
	refreshgrille(g);
}




int main(int argc, char *argv[]) {
	grid g;int size,nbcoups;
	printf("Entrer la taille du grille ");
	scanf("%d",&size);
	printf("Entrer le nombre de coups ");
	scanf("%d",&nbcoups);
	nbcoups=nbcoups;
	SDL_Rect position;
	g=init_grid(size);
	int continuer=1;
	SDL_Surface *ecran = NULL,*texte=NULL;
	SDL_Event event;
  const SDL_VideoInfo* info = NULL;
  SDL_Surface *ima=NULL;


  if( SDL_Init( SDL_INIT_VIDEO ) < 0 ) {
      /* Failed, exit. */
      fprintf( stderr, "Video initialization failed: %s\n", SDL_GetError( ) );
      SDL_Quit( );
  }

	if(TTF_Init() == -1){
    fprintf(stderr, "Erreur d'initialisation de TTF_Init : %s\n", TTF_GetError());
    exit(EXIT_FAILURE);
	}
	TTF_Font *police = NULL;
	police = TTF_OpenFont("angelina.ttf", 65);
	SDL_Color couleurNoire = {0, 0, 0},couleurBlanche = {255, 255, 255};
	int nbr_mvm=0;
	char mouvement[100];
	position.x = 300;
	position.y = 750;


	info = SDL_GetVideoInfo( );
  if( !info ) {
      /* This should probably never happen. */
      fprintf( stderr, "Video query failed: %s\n", SDL_GetError( ) );
      SDL_Quit( );
  }

	ecran=SDL_SetVideoMode(600,800, 32, SDL_HWSURFACE);
	SDL_WM_SetCaption("ColorFlood", NULL);



	ima = SDL_LoadBMP("./cerise.bmp");
	fillScreen(ecran, 255,255,255);
	grid_print(&g);
	printgrille(ecran,g);
	printcouleurs(ecran);

	sprintf(mouvement,"%d",nbcoups);
	texte = TTF_RenderText_Shaded(police, mouvement,couleurNoire,couleurBlanche);
	SDL_BlitSurface(texte, NULL, ecran,&position);



  while (continuer && !test_same_colour(&g) && nbcoups>0) {
		SDL_WaitEvent(&event);
    switch(event.type) {
        case SDL_QUIT:
            continuer = 0;
            break;
				case SDL_KEYDOWN:
            switch (event.key.keysym.sym)
            {
                case SDLK_ESCAPE: /* Appui sur la touche Echap, on arrête le programme */
                    continuer = 0;
                    break;
                default:break;
            }
				case SDL_MOUSEBUTTONUP:
						if (event.button.button == SDL_BUTTON_LEFT){
							if(event.button.y>610 && event.button.y<700){
								nbr_mvm++;
								drawRectangle(ecran,300,750,100,255,255,255);
								nbcoups--;
								sprintf(mouvement,"%d",nbcoups);
								texte = TTF_RenderText_Shaded(police, mouvement,couleurNoire,couleurBlanche);
								SDL_BlitSurface(texte, NULL, ecran,&position);

									if(event.button.x<100){
										jouer(ecran,g,'V'); break;
									}
									if(event.button.x<200){
										jouer(ecran,g,'R'); break;
									}
									if(event.button.x<300){
										jouer(ecran,g,'B'); break;
									}
									if(event.button.x<400){
										jouer(ecran,g,'J'); break;
									}
									if(event.button.x<500){
										jouer(ecran,g,'M'); break;
									}
									if(event.button.x<600){
										jouer(ecran,g,'G'); break;
									}
								}
						}
					}
			}
	if(test_same_colour(&g)) printf("Vous avez resolu la grille en %d mouvements \n",nbr_mvm);
	else printf("Vous avez perdu");
	TTF_CloseFont(police);
	TTF_Quit();
	SDL_Quit();

	return 0;
}
