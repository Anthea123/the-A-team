# LotD : Color Flood 

## The A-Team  

### Fichiers inclus
* grid_color.c : Contient toutes les fonctions de base utilisées dans tous les lots précédents
* grid_color.h : Contient les prototypes des fonctions du module grid_color et leurs commentaires Doxygen
* solveur_rapide.c : Contient l'implémentation des fonctions du solveur optimisé
* solveur_rapide.h : Contient les prototypes des fonctions du solveur optimisé
* unit_test.c : Contient les tests unitaires des fonctions du solveur optimisé
* unit_test.h : Contient les prototypes des tests unitaires
* loop_game.c : Contient les fonctions pour l'application Color Flood en mode console
* loop_game.h : Contient les prototypes des fonctions implémentées dans loop_game.c
* main_jeu.c : Permet d'exécuter l'application en mode console
* main_test.c : Exécute les tests unitaires
* SDL.c : Contient les fonctions de base pour le jeu en mode graphique
* SDL.h : Contient les prototypes des fonctions de base pour le jeu en mode graphique
* solveurSDL.c : 
* Doxyfile : Contient la configuration utilisée par Doxygen pour générer la documentation
* Makefile : Permet de générer les exécutables et la documentation
* Rapport_Lot_D.pdf : Rapport du Lot D
* color_flood.gan : diagramme de Gantt du projet fait avec le logiciel GanttProject
* gantt_ressources.png et gantt_tâches.png : impression diagramme de Gantt des tâches et des ressources si on n'utilise pas le même logiciel Gantt


### Instructions d'installation

Pour la documentation doxygen:

`sudo apt-get install doxygen`

Pour les tests unitaires, la librairie CUnit est nécessaire:

`sudo apt-get install libcunit1 libcunit1-doc libcunit1-dev`

Pour l'interface graphique SDL:

`sudo apt-get install libsdl1.2-dev libsdl-gfx1.2-dev libsdl-ttf2.0-dev libfreeimage-dev`

### Instructions d'utilisation en mode texte

Pour compiler et exécuter le solveur en mode texte:

`make ./exsolveur arg` où `arg` est la taille de la grille

Pour compiler et exécuter le jeu en mode texte:

`make ./jeu`

Pour compiler et exécuter les tests:

`make ./tests`

Pour tester l'absence de fuites de mémoire (Valgrind

`valgrind ./exsolveur arg` où `arg` est la taille de la grille

`valgrind ./tests`

Pour générer la documentation (Doxygen):

`doxygen Doxyfile `

Pour nettoyer le répertoire:

`make clean`

### Instructions d'utilisation de l'application Color Flood en mode graphique



Pour compiler et exécuter le solveur en mode texte:

`make ./solveurSDL`

### Instructions de documentation

Tous les commentaires au format doxygen sont mis dans les headers pour éviter la duplication dans la documentation
D'autres commentaires normaux sont inclus dans les fichiers sources
Toutes les fonctions et leurs conceptions sont détaillées dans le rapport 
