#LotC

##The A-Team

### Fichiers inclus
* grid_color.c : Contient toutes les fonctions de base utilisées dans tous les lots précédents
* grid_color.h : Contient les prototypes des fonctions du module grid_color et leurs commentaires Doxygen
* pile.c : Contient  l'implémentation des fonctions de base des piles
* pile.h : Contient les prototypes des fonctions de base implémentées dans pile.c
* solvpile.c : 
* solvpile.h :  Contient les prototypes des fonctions implémentées dans solvpile.c
* solveur.c : Contient l'implémentation des fonctions du solveur
* solveur.h : Contient les prototypes des fonctions du solveur
* unit_test.c : Contient les tests unitaires des fonctions des piles et de solvpile et les tests unitaires du solveur 
* unit_test.h : Contient les prototypes des tests unitaires
* mainsolveur.c : 
* main_test.c : 
* Doxyfile : Contient la configuration utilisée par Doxygen pour générer la documentation
* Makefile : Permet de générer les exécutables et la documentation
* Rapport_Lot_C.pdf : Rapport du Lot C


###Instructions d'installation

Pour la documentation doxygen:

`sudo apt-get install doxygen`

Pour les tests unitaires, la librairie CUnit est nécessaire:

`sudo apt-get install libcunit1 libcunit1-doc libcunit1-dev`

Pour l'interface graphique SDL:

`sudo apt-get install libsdl1.2-dev libsdl-gfx1.2-dev libsdl-ttf2.0-dev libfreeimage-dev`

###Instructions d'utilisation

Pour compiler et exécuter le solveur en mode texte:

`make ./exsolveur`


Pour compiler et exécuter les tests:

`make ./tests`

Pour tester l'absence de fuites de mémoire (Valgrind

`valgrind ./exsolveur`
`valgrind ./tests`

Pour générer la documentation (Doxygen):

`doxygen Doxyfile `

Pour nettoyer le répertoire:

`make clean`

###Instructions d'utilisation du solveur en mode graphique 

Pour le Solveur en mode graphique pour sélectionner un choix du menu on utilise les fleches haut et bas du clavier et pour choisir la taille on utilise les fleches gauche et droite et puis Espace pour selectionner notre choix, on choisit ensuite la couleur avec le curseur, et pour rejouer une nouvelle fois on appuie sur Espace sinon pour quitter on appuie sur echap au clavier.

###Instructions de documentation

Tous les commentaires au format doxygen sont mis dans les headers pour éviter la duplication dans la documentation
D'autres commentaires normaux sont inclus dans les fichiers sources
Toutes les fonctions et leurs conceptions sont détaillées dans le rapport 
