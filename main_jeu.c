#include "loop_game.h"

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
	game();

	return 0;
}
