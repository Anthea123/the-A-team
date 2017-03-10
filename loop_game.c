#include "loop_game.h"
#include "grid_color.h"

/*	on demande à l'utilisateur de saisir une couleur , si celle ci n'est pas valide et 
	tant que l'utilisateur ne quitte pas avec 'Q' on lui redemande de sasir une couleur
	valide*/
char get_colour(){
    char c;
	char tmp[3];

    printf("Entrer une couleur:\n");
	scanf("%s", tmp);
	c = tmp[0];

	while(!test_is_color(c) && c != 'Q'){
		printf("Entrer une couleur:\n");
		scanf("%s", tmp);
		c = tmp[0];
	}

    return c;
}

/*	on demande à l'utilisateur de saisir une taille de la grille*/
int get_size(){
    int s;

    printf("Entrer la taille de la grille:\n");
	scanf("%d",&s);
	
	while(s < 1)
	{
		printf("Entrer la taille de la grille:\n");
		scanf("%d", &s);
	}

    return s;
}

/*	on demande à l'utilisateur de saisir un nombre de coups , le nombre de coups
	minimal est 1 tant que l'utilisateur ne saisit pas un nombre de coups valide
	on lui redemande de sasir un nombre de coups*/
int get_nombre_coups()
{
    int nb;

    printf("Entrer le nombre de coups autorisé:\n");
	scanf("%d", &nb);
	
	while(nb < 1)
	{
		printf("Entrer le nombre de coups autorisé:\n");
		scanf("%d", &nb);
	}

    return nb;
}

/*	effectue les changements nécessaires à la grille à chaque tour de jeu*/
void turn(int *coups_restants, int *nbr_mvm, grid *g, char c){
	change_color(g, c);
	refresh_grid(g);
	*nbr_mvm = *nbr_mvm+1;
	*coups_restants = *coups_restants-1;
	grid_print(g);
	printf("Il vous reste %d coups\n", *coups_restants);
	detect_flood(g, 0, 0, g->array[0][0]);
}

/*	si la grille est de couleur unie -> Victoire
	sinon si l'utilisateur quitte au milieu de la partie -> Au revoir
	sinon l'utilisateur perd*/
void check(grid *g, int test_quit, int nbr_mvm){
	if(test_same_colour(g))
	{
		printf("Victoire! Vous avez resolu la grille en %d mouvements \n",nbr_mvm);
	}
	else
	{
		if(test_quit)
		{
			printf("Au revoir!");
		}
		else
		{
			printf("Vous avez perdu");
		}
	}
}

/*
	l'utilisateur saisit une taille qui est testée par la fonction get_size
	il saisit ensuite le nombre de coups autorisés qui doit être valide à 
*/
void game(){
    int size;
	int coups_restants;
	int nbr_mvm = 0;
	int test_quit = 0;
	char c;
	grid g;

	size = get_size();

	 
        coups_restants = get_nombre_coups();

		g = init_grid(size);

		grid_print(&g);
		detect_flood(&g, 0, 0, g.array[0][0]);
		
		while(!test_same_colour(&g) && coups_restants > 0 && !test_quit){
			
            c = get_colour();

			if(c != 'Q'){
				turn(&coups_restants, &nbr_mvm, &g, c);
			}
			else{
				test_quit = 1;
			}
		}
		
		check(&g, test_quit, nbr_mvm);

		free_grid(&g);
	
}