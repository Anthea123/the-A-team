#LotA

##The A-Team

### Fichiers inclus

* grid_color.c : Contient toutes les fonctions de base
* grid_color.h : Contient les prototypes des fonctions du module grid_color et leurs commentaires Doxygen
* unit_test.c : Contient les fonctions des tests unitaires des fonctions du module grid_color
* unit_test.h : Contient les prototypes des fonctions du module unit_test et leurs commentaires Doxygen
* main.c : Contient la définition des suites de tests unitaires et permettre de générer l'exécutable tests
* main_jeu.c : Contient une boucle de jeu pour mettre en évidence le bon fonctionnement des fonctions de base pour le jeu et permettra de générer l'exécutable jeu
* Doxyfile : Contient la configuration utilisée par Doxygen pour générer la documentation
* same_color : Définit une grille dont toutes les cases ont la même couleur
* grille1, grille2, grille3 et grille4, et belong1, belong2, belong3 et belong4 : Définissent les grilles avec des tâches, et les tâches

Ces derniers fichiers sont nécessaires pour l'exécution des tests unitaires

###Instructions d'installation

Pour la documentation doxygen:

`sudo apt-get install doxygen`

Pour les tests unitaires, la librairie CUnit est nécessaire:
`sudo apt-get install libcunit1 libcunit1-doc libcunit1-dev`

###Instructions d'utilisation

Pour compiler et exécuter les tests unitaires:
`make 
./tests`

Pour compiler et exécuter la boucle de jeu:`make`

Pour tester l'absence de fuites de mémoire (Valgrind):
valgrind ./tests
valgrind ./jeu

Pour générer la documentation (Doxygen):
doxygen Doxyfile

Pour nettoyer le répertoire:
make clean

Tous les commentaires au format doxygen sont mis dans les headers pour éviter la duplication dans la documentation
D'autres commentaires normaux sont inclus dans les fichiers sources
Toutes les fonctions et leurs conceptions sont détaillées dans le rapport 

Equipe : The A-Team
