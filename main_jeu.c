#include "grid_color.h"

int main(){

	int size;
	grid g;
	printf("Entrer la taille de la grille ");
	scanf("%d",&size);
	g=init_grid(size);
	int nbr_mvm=0;
	char c='U';
	do{
		grid_print(&g);
		identiftache(g,0,0,g.array[0][0]);
		printf("Entrer une couleur ");
		getchar();
		scanf("%c",&c);
		changecolor(g,c);
		refreshgrille(g);
		nbr_mvm++;
	}while(!test_same_colour(&g));
	grid_print(&g);
	printf("Vous avez resolu la grille en %d mouvements ",nbr_mvm);
	free_grid(&g);

	return 0;
}
