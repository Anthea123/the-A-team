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
	grid g;
	int nbr_mvm=0;
	char c='U';
	int nbr_coup=0;

	printf("Entrer la taille de la grille ");
	scanf("%d",&size);
	getchar();

	if (size > 0)
	{

				printf("Entrer le nombre de coup autorisé\n ");
				scanf("%d",&nbr_coup);
				getchar();

				g=init_grid(size);
				
				do{
					grid_print(&g);
					detect_flood(&g,0,0,g.array[0][0]);
					printf("Entrer une couleur ");
					scanf("%c",&c);
					getchar();
					nbr_coup--;
					
					if(!test_is_color(c))
					{
						printf("Couleur non valide \n");
						break;
					}
					change_color(&g,c);
					refresh_grid(&g);
					nbr_mvm++;
					printf("Il vous reste %d coups\n", nbr_coup);
				}while(!test_same_colour(&g) && nbr_coup > 0);

	}
	grid_print(&g);
	if(nbr_mvm <= nbr_coup)
	{
		printf("Victoire : Vous avez resolu la grille en %d mouvements\n",nbr_mvm);
	}
	else 
	{
		printf("Vous avez perdu\n");
	}

	free_grid(&g);

	return 0;
}
