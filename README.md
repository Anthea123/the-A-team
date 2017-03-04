#LotB

##The A-Team

### Fichiers inclus
* exSDL.c : 
* SDLMain.m :
* SDLMain.h :
* test.c : Contient la définition des suites de tests unitaires et permet de générer l'exécutable tests
* main_jeu.c : Contient la boucle de jeu en mode texte
* main_jeu_SDL.c : Contient la boucle de jeu en mode graphique
* grid_color.c : Contient toutes les fonctions de base
* grid_color.h : Contient les prototypes des fonctions du module grid_color et leurs commentaires Doxygen
* Doxyfile : Contient la configuration utilisée par Doxygen pour générer la documentation
* Makefile : Permet de générer les exécutables et la documentation
* resultat-valgrind: Contient les résultats de Valgrind pour les deux exécutables


###Instructions d'installation

Pour la documentation doxygen:

`sudo apt-get install doxygen`

Pour les tests unitaires, la librairie CUnit est nécessaire:
`sudo apt-get install libcunit1 libcunit1-doc libcunit1-dev`

Pour l'interface graphique SDL:
`sudo apt-get install libsdl1.2-dev libsdl-gfx1.2-dev libsdl-ttf2.0-dev libfreeimage-dev`

###Instructions d'utilisation

Pour compiler et exécuter les tests unitaires:
`make 
./tests`

Pour compiler et exécuter la boucle de jeu:
`make
./jeu`

Pour tester l'absence de fuites de mémoire (Valgrind):
`valgrind ./tests
valgrind ./jeu`

Pour générer la documentation (Doxygen):
`doxygen Doxyfile`

Pour nettoyer le répertoire:
`make clean`

Tous les commentaires au format doxygen sont mis dans les headers pour éviter la duplication dans la documentation
D'autres commentaires normaux sont inclus dans les fichiers sources
Toutes les fonctions et leurs conceptions sont détaillées dans le rapport 



