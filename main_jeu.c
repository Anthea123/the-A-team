#include "grid_color.h"

/*Ce main contient une boucle permettant de voir la propagation de la composante 4-connexe à chaque fois
 que l'utilisateur rentre une couleur.
 
 On envoie un message à l'utilisateur pour rentrer la taille de grille désirée.
 On initialise la grille aléatoirement avec init_grid.
 On entre dans la boucle.
 On detecte la tâche qui commence à la case de coordonnées (0, 0).
 L'utilisateur rentre la couleur qu'il a choisie. Si cette couleur est valide, on change la couleur de la 
 composante 4-connexe avec change_color.
 On réinitialise le tableau belong de la grille à 0, pour que la tâche puisse être détectée à l'itération 
 suivante.
 On répète tant que le test_same_colour est faux.
 On affiche la grille à chaque itération.
 À la fin on affiche le nombre de mouvements qu'a fait l'utilisateur et on libère la grille.*/

int main()
{ 

	int size;
	int coups_restants;
	int nbr_mvm = 0;
	int test_quit = 0;
	grid g;

	printf("Entrer la taille de la grille:\n");
	scanf("%d",&size);
	getchar();

	if(size > 0)
	{
		printf("Entrer le nombre de coups:\n");
		scanf("%d", &coups_restants);

		g=init_grid(size);

		grid_print(&g);
		detect_flood(&g,0,0,g.array[0][0]);
		
		while(!test_same_colour(&g) && coups_restants > 0 && !test_quit){
			
			printf("Entrer une couleur:\n");
			scanf("%c", &c);
			c = getchar();

			while(!test_is_color(c) && c != 'Q'){
				printf("Entrer une couleur:\n");
				scanf("%c", &c);
				c = getchar();
			}
			if(c != 'Q'){
				change_color(&g,c);
				refresh_grid(&g);
				nbr_mvm = nbr_mvm+1;
				coups_restants = coups_restants-1;
				grid_print(&g);
				printf("Il vous reste %d coups\n", coups_restants);
				detect_flood(&g,0,0,g.array[0][0]);
			}
			else{
				test_quit = 1;
			}
			
		}
	

		grid_print(&g);
		
		if(coups_restants >= 0 && !test_quit)
		{
			printf("Victoire! Vous avez resolu la grille en %d mouvements \n",nbr_mvm);
		}
		else
		{
			if(test_quit == 1)
			{
				printf("Au revoir!");
			}
			else
			{
				printf("Vous avez perdu");
			}
		}

		free_grid(&g);
	}

	return 0;
}
