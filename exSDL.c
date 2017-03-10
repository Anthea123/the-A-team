#include "grid_color.h"
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
	SDL_Color couleurNoire = {0, 0, 0};
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



int main() {
	while(1){
	grid g;int size=6,nbcoups=14;
	char sizeg[100];
	char coups[100];
	SDL_Rect position;
	int continuer=1;
	SDL_Surface *ecran = NULL,*texte=NULL,*menu1=NULL,*menu2=NULL,*menu3=NULL;
	SDL_Event event,touche;
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
	TTF_Font *police = NULL,*pmenu=NULL;
	police = TTF_OpenFont("LOTB.ttf", 30);
	SDL_Color couleurNoire = {0, 0, 0},couleurBlanche = {255, 255, 255},couleurRouge={255,0,0},couleurBleu={0,0,255},couleurgris={127,127,127};
	int nbr_mvm=0;
	char mouvement[100];




	info = SDL_GetVideoInfo( );
  if( !info ) {
      /* This should probably never happen. */
      fprintf( stderr, "Video query failed: %s\n", SDL_GetError( ) );
      SDL_Quit( );
  }

	ecran=SDL_SetVideoMode(600,800, 32, SDL_HWSURFACE);
	SDL_WM_SetCaption("ColorFlood", NULL);
	afficherMenu(ecran,size,nbcoups);
	drawRectangle(ecran,10,300,10,0,0,0);

	int compteur=1,fleche=300;
	while(compteur){
		SDL_WaitEvent(&touche);
		{
			switch(touche.type)
			 {
			 case SDL_QUIT:
					 return 0;
			 case SDL_KEYDOWN: ///Si une touche à été appuyée
					 switch(touche.key.keysym.sym)
					 {
					 case SDLK_DOWN:
					 	{
								fleche++;
								switch(fleche%3)
									{
									case 0:drawRectangle(ecran,10,300,10,0,0,0);drawRectangle(ecran,10,400,10,255,255,255);drawRectangle(ecran,10,500,10,255,255,255);break;
									case 1:	drawRectangle(ecran,10,400,10,0,0,0);drawRectangle(ecran,10,500,10,255,255,255);drawRectangle(ecran,10,300,10,255,255,255);	break;
									case 2: drawRectangle(ecran,10,500,10,0,0,0);drawRectangle(ecran,10,300,10,255,255,255);drawRectangle(ecran,10,400,10,255,255,255);	break;
								}
						break;
						}
					case SDLK_UP:
					{
						fleche--;
						switch(fleche%3)
							{
							case 0:drawRectangle(ecran,10,300,10,0,0,0);drawRectangle(ecran,10,400,10,255,255,255);drawRectangle(ecran,10,500,10,255,255,255);break;
							case 1:	drawRectangle(ecran,10,400,10,0,0,0);drawRectangle(ecran,10,500,10,255,255,255);drawRectangle(ecran,10,300,10,255,255,255);	break;
							case 2: drawRectangle(ecran,10,500,10,0,0,0);drawRectangle(ecran,10,300,10,255,255,255);drawRectangle(ecran,10,400,10,255,255,255);	break;
						}
				break;
					}
					 case SDLK_RIGHT:
					 {
						 switch(fleche%3)
						 	{
								case 0 : {
									size++;
									afficherMenu(ecran,size,nbcoups);
									break;}
								case 1 : {
									nbcoups++;
									afficherMenu(ecran,size,nbcoups);
									break;}
							}
							break;
					 }
					 case SDLK_LEFT:
					 {
						 switch(fleche%3)
						 	{
								case 0 : {
									if(size>2){size--;}
									afficherMenu(ecran,size,nbcoups);
									break;}
								case 1 : {
									if(nbcoups>1){nbcoups--;}
									afficherMenu(ecran,size,nbcoups);
									break;}
							}
							break;
					 }

					 case SDLK_SPACE: ///Si la touche appuyée est espace
					 			compteur=0; //jouer(); ///LANCE LE JEU
							 break;
					 case SDLK_ESCAPE: /* Appui sur la touche Echap, on arrête le programme */
								return 0;
					 default : ;
					 }

			 default : ;
			 }

	 }

 }
 	fillScreen(ecran, 255,255,255);
	ima = SDL_LoadBMP("./cerise.bmp");
	g=init_grid(size);
	printgrille(ecran,g);
	printcouleurs(ecran);
	int cinit=nbcoups;
	sprintf(mouvement,"%d/%d",nbcoups,cinit);
	texte = TTF_RenderText_Shaded(police, mouvement,couleurNoire,couleurBlanche);
	position.x = 10;
	position.y = 10;
	SDL_BlitSurface(texte, NULL, ecran,&position);
	SDL_Flip(ecran);


  while (continuer ) {
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
							if(event.button.y>710 && event.button.y<780){
								nbr_mvm++;
								drawRectangle(ecran,10,10,80,255,255,255);
								drawRectangle(ecran,120,10,90,255,255,255);
								nbcoups--;
								sprintf(mouvement,"%d/%d",nbcoups,cinit);
								texte = TTF_RenderText_Shaded(police, mouvement,couleurNoire,couleurBlanche);
								SDL_BlitSurface(texte, NULL, ecran,&position);

									if(event.button.x<130 && event.button.x>60){
										jouer(ecran,g,'V'); break;
									}
									if(event.button.x<210 && event.button.x>140){
										jouer(ecran,g,'R'); break;
									}
									if(event.button.x<290 && event.button.x>220){
										jouer(ecran,g,'B'); break;
									}
									if(event.button.x<370 && event.button.x>300){
										jouer(ecran,g,'J'); break;
									}
									if(event.button.x<450 && event.button.x>380){
										jouer(ecran,g,'M'); break;
									}
									if(event.button.x<550 && event.button.x>460){
										jouer(ecran,g,'G'); break;
									}
								}
						}
					}
				


				if(test_same_colour(&g)) {
					SDL_Surface *wintext=NULL;
					police = TTF_OpenFont("LOTB.ttf", 15);
					char win[100];
					fillScreen(ecran, 255,255,255);
					sprintf(win,"Vous avez resolu la grille \n en %d mouvements",nbr_mvm);
					wintext=TTF_RenderText_Shaded(police,win,couleurBleu,couleurBlanche);
					printgrille(ecran,g);
					position.x=30;
					position.y=700;
					SDL_BlitSurface(wintext, NULL, ecran,&position);
					SDL_Flip(ecran);
					SDL_Event retry;
					SDL_WaitEvent(&retry);
					if(retry.type==SDL_KEYDOWN ){continuer=0;break;}
			}
			if(nbcoups==0){
				SDL_Surface *losetext=NULL;
				fillScreen(ecran, 255,255,255);
				losetext=TTF_RenderText_Shaded(police,"Vous avez perdu",couleurRouge,couleurBlanche);
				printgrille(ecran,g);
				position.x=30;
				position.y=700;
				SDL_BlitSurface(losetext, NULL, ecran,&position);
				SDL_Flip(ecran);
				SDL_Event retry;
				SDL_WaitEvent(&retry);
				if(retry.type==SDL_KEYDOWN) continuer=0;break;
				}
		}

	TTF_CloseFont(police);
	TTF_Quit();
	SDL_Quit();
	}
	return 0;
}
