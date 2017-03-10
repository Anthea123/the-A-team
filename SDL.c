#include "grid_color.h"
#include "SDL.h"

/*
 compilation soous Linux : gcc -o exSDL exSDL.c -lSDL
 compilation sur Mac : gcc -o exSDL -I/Library/Frameworks/SDL.framework/Headers  exSDL.c SDLmain.m -framework SDL -framework Cocoa
*/

int autoDraw=0;

// px, py coordonnées haut, gauche du pixel
void drawRectangle(SDL_Surface *ecran, int px, int py, int size, int r, int g, int b) {
    SDL_Rect rect;
    rect.x=px;
    rect.y=py;
    rect.h=rect.w=size;
    SDL_FillRect(ecran, &rect, SDL_MapRGB(ecran->format, r, g, b));
    SDL_Flip(ecran);
}


void fillScreen(SDL_Surface *ecran, int r, int g, int b) {
    SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, r, g, b));
    SDL_Flip(ecran);
}


void printgrille(SDL_Surface *ecran,grid g){
		int size=g.size;
		int sizerectan=560/size;
		for(int i=0;i<size;i++){
			for(int j=0;j<size;j++){
				switch (g.array[j][i]) {
					case 'V':
								drawRectangle(ecran,i*sizerectan+20,j*sizerectan+100,sizerectan,0,255,0);break;
					case 'R':
								drawRectangle(ecran,i*sizerectan+20,j*sizerectan+100,sizerectan,255,0,0);break;
					case 'B':
								drawRectangle(ecran,i*sizerectan+20,j*sizerectan+100,sizerectan,0,0,255);break;
					case 'J':
								drawRectangle(ecran,i*sizerectan+20,j*sizerectan+100,sizerectan,255,255,0);break;
					case 'M':
								drawRectangle(ecran,i*sizerectan+20,j*sizerectan+100,sizerectan,114,89,63);break;
					case 'G':
								drawRectangle(ecran,i*sizerectan+20,j*sizerectan+100,sizerectan,127,127,127);break;
					default:
									;
				}
			}
		}

}

void printcouleurs(SDL_Surface *ecran){
		drawRectangle(ecran,60,710,70,0,255,0);
		drawRectangle(ecran,140,710,70,255,0,0);
		drawRectangle(ecran,220,710,70,0,0,255);
		drawRectangle(ecran,300,710,70,255,255,0);
		drawRectangle(ecran,380,710,70,114,89,63);
		drawRectangle(ecran,460,710,70,127,127,127);
}

void jouer(SDL_Surface *ecran,grid g,char c){
	detect_flood(&g,0,0,g.array[0][0]);
	change_color(&g,c);
	printgrille(ecran,g);
	refresh_grid(&g) ;
}

void afficherMenu(SDL_Surface *ecran,int size,int nbcoups){
	SDL_Rect position;
	char sizeg[100];
	char coups[100];
	TTF_Font *police = NULL;
	police = TTF_OpenFont("LOTB.ttf", 15);
	fillScreen(ecran, 255,255,255);
	SDL_Surface *menu1=NULL,*menu2=NULL,*menu3=NULL;
	sprintf(sizeg,"Entrer la taille de la grille :  <|  %d  |>",size);
	menu1=TTF_RenderText_Blended(police,sizeg,couleurNoire);
	position.x = 30;
	position.y = 300;
	SDL_BlitSurface(menu1, NULL, ecran,&position);

	sprintf(coups,"Entrer le nombre de coups autorsisees  :  <|  %d  |>",nbcoups);
	menu2=TTF_RenderText_Blended(police,coups,couleurNoire);
	position.x = 30;
	position.y = 400;
	SDL_BlitSurface(menu2, NULL, ecran,&position);

	menu3=TTF_RenderText_Blended(police, "QUIT",couleurNoire);
	position.x = 30;
	position.y = 500;
	SDL_BlitSurface(menu3, NULL, ecran,&position);
	SDL_Flip(ecran);

}
void initialise(){
  const SDL_VideoInfo* info = NULL;
  if( SDL_Init( SDL_INIT_VIDEO ) < 0 ) {
      /* Failed, exit. */
      fprintf( stderr, "Video initialization failed: %s\n", SDL_GetError( ) );
      SDL_Quit( );
  }
  if(TTF_Init() == -1){
    fprintf(stderr, "Erreur d'initialisation de TTF_Init : %s\n", TTF_GetError());
    exit(EXIT_FAILURE);
  }
  info = SDL_GetVideoInfo( );
  if( !info ) {
      /* This should probably never happen. */
      fprintf( stderr, "Video query failed: %s\n", SDL_GetError( ) );
      SDL_Quit( );
  }
}
void dessinerfleche(SDL_Surface *ecran,int fleche){
  switch(fleche%3)
    {
    case 0:drawRectangle(ecran,10,300,10,0,0,0);drawRectangle(ecran,10,400,10,255,255,255);drawRectangle(ecran,10,500,10,255,255,255);break;
    case 1:	drawRectangle(ecran,10,400,10,0,0,0);drawRectangle(ecran,10,500,10,255,255,255);drawRectangle(ecran,10,300,10,255,255,255);	break;
    case 2: drawRectangle(ecran,10,500,10,0,0,0);drawRectangle(ecran,10,300,10,255,255,255);drawRectangle(ecran,10,400,10,255,255,255);	break;
  }
}
int finjeu(SDL_Surface *ecran,TTF_Font *police,int WL,int nbr_mvm){
  SDL_Rect position;
	SDL_Color couleurRouge={255,0,0},couleurBleu={0,0,255};
  if(WL==0){
    SDL_Surface *wintext=NULL;
    police = TTF_OpenFont("LOTB.ttf", 15);
    char win[100];

    sprintf(win,"Vous avez resolu la grille \n en %d mouvements",nbr_mvm);
    wintext=TTF_RenderText_Blended(police,win,couleurBleu);
    position.x=30;
    position.y=700;
    SDL_BlitSurface(wintext, NULL, ecran,&position);
    SDL_Flip(ecran);
    SDL_Event retry;
    SDL_WaitEvent(&retry);
    if(retry.type==SDL_KEYDOWN ){return 1;}
}
else if(WL==1){
  SDL_Surface *losetext=NULL;

  losetext=TTF_RenderText_Blended(police,"Vous avez perdu",couleurRouge);
  position.x=30;
  position.y=700;
  SDL_BlitSurface(losetext, NULL, ecran,&position);
  SDL_Flip(ecran);
  SDL_Event retry;
  SDL_WaitEvent(&retry);
  if(retry.type==SDL_KEYDOWN) return 1;
  }
}
