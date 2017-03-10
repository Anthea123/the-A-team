#include "loop_game.h"

/*Ce main contient une boucle permettant de voir la propagation de la composante 4-connexe à chaque fois
 que l'utilisateur rentre une couleur.
 
 On envoie un message à l'utilisateur pour rentrer la taille de grille désirée ainsi que le nombre de coups autorisés.
 On initialise la grille aléatoirement avec init_grid.

 On detecte la tâche qui commence à la case de coordonnées (0, 0).
 L'utilisateur rentre la couleur qu'il a choisie. Si cette couleur est valide, on change la couleur de la 
 composante 4-connexe avec change_color.
 
 On réinitialise le tableau belong de la grille à 0, pour que la tâche puisse être détectée à l'itération 
 suivante.
 
 On répète tant que le test_same_colour est faux et tant que le nombre de coups autorisés est > 0 .
 On affiche la grille à chaque itération.
 
 Victoire au cas où la grille est de la même couleur et qu'on a pas dépassé le nombre de coups autorisés.
 Si l'utilisateur tape "Q" il sort du jeu on lui renvoie un message Au revoir.*/

int main()
{ 
	game();

	return 0;
}
