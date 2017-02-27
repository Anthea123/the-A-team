/**
*	\file unit_test.c
*	\brief bibliothèque permettant de faire les tests unitaires du module grid_color
*	\author Loubna Anthea Abdellah Bader
*	\date 27 Feb 2017
*/

#include "CUnit/CUnit.h"
#include "CUnit/Basic.h"
#include "unit_test.h"
#include <math.h>

/* fonction pour tester si une grille est bien remplie
	renvoie 1 (test=1) si elle est de taille valide et remplie par des couleurs valides
	et 0 sinon */

int test_filled_grid(grid *grille)
{
	int i, j;
	int test = 1; 
	
	if(grille->size <= 0)
	{
		if(grille->array != NULL)
		{
			test = 0;
		}
	}
	
	else
	{
		for(i = 0; i < grille->size; i = i+1)
		{
			for(j = 0; j < grille->size; j = j+1)
			{
				if(!(test_is_color(grille->array[i][j])))
				{
					test = 0;
				}
			}
		}
	}
	
	return test;	
}
/* test unitaire d'init grid */
void test_init_grid(void)
{

	grid grille1, grille2, grille3, grille4;
	
	grille1 = init_grid(0);
	grille2 = init_grid(6);
	grille3 = init_grid(12);
	grille4 = init_grid(20);
	
	CU_ASSERT(test_filled_grid(&grille1) == 0);
	CU_ASSERT(test_filled_grid(&grille2) == 1);
	CU_ASSERT(test_filled_grid(&grille3) == 1);
	CU_ASSERT(test_filled_grid(&grille4) == 1);
	
	free_grid(&grille1);
	free_grid(&grille2);
	free_grid(&grille3);
	free_grid(&grille4);
}
/*  fonction pour tester que ce qu'il y a dans une grille correspond à ce qu'il y a dans un fichier 
	on ouvre le fichier name_file passé en paramètre en mode lecture
	on compte ses caractères s'il est de taille supérieur à la grille on les compare
	s'ils sont pareils test =1
	sinon s'ils sont différents ou que la taille du fichier est inférieur à la grille test=0*/
int test_grid_file(char name_file[], grid *grille)
{

	char a;
	FILE * f = fopen(name_file, "r");
	int i, j;
	int compteur = count_file(name_file);
	int test = 1;
	
	if(compteur >= grille->size*grille->size)
	{
		for(i = 0; i < grille->size; i = i+1) 
		{
			for(j = 0; j < grille->size; j = j+1)
			{
				fread(&a, sizeof(char), 1 , f);
				if(grille->array[i][j] != a)
				{
					test = 0;
				}
			}
		}
	}
	else
	{
		test = 0;
	}
	
	fclose(f);

	return test;
}
/*  test unitaire de la fonction init_grid_file*/
void test_init_grid_file(void)
{
	grid grille1, grille2, grille3, grille4;
	
	grille1 = allocate_grid(1);
	grille2 = allocate_grid(6);
	grille3 = allocate_grid(13);
	grille4 = allocate_grid(24);	
	
	fill_file("fichier1", 1);
	fill_file("fichier2", 6);
	fill_file("fichier3", 12);
	fill_file("fichier4", 24);
	
	init_grid_file("fichier1", &grille1);
	init_grid_file("fichier2", &grille2);
	init_grid_file("fichier3", &grille3);
	init_grid_file("fichier4", &grille4);

	CU_ASSERT(test_grid_file("fichier1", &grille1) == 1);	
	CU_ASSERT(test_grid_file("fichier2", &grille2) == 1);
	CU_ASSERT(test_grid_file("fichier3", &grille3) == 0);
	CU_ASSERT(test_grid_file("fichier4", &grille4) == 1);
	
	free_grid(&grille1);
	free_grid(&grille2);
	free_grid(&grille3);
	free_grid(&grille4);

}
/* fonction pour tester si le fichier est bien rempli
	on ouvre le fichier name_file passé en paramètre en mode lecture
	si count_file de ce fichier est différents de n*n ou qu'une couleur n'est pas valide test=0
	sinon test=1
	on ferme le fichier à la fin*/
int test_file(char name_file[], int n)
{
	int test = 1;
	FILE * f = fopen(name_file, "r");
	
	if(f)
	{
		char a;
		int compteur = count_file(name_file);
	
		if(compteur != n*n)
		{
			test = 0;
		}
		else
		{
			while(fread(&a, sizeof(char), 1, f))
			{
				if(!test_is_color(a))
				{
					test = 0;
				}
			}
		}
	
		fclose(f);
	}
	else
	{
		test = 0;
	}
	
	return test;

}
/* test unitaire de la fonction fill_file */
void test_fill_file(void)
{
	fill_file("fichier5", 6);
	fill_file("fichier6", 0);
	fill_file("fichier7", -1);
	fill_file("fichier8", 12);
	
	CU_ASSERT(test_file("fichier5", 6) == 1);
	CU_ASSERT(test_file("fichier6", 0) == 0);
	CU_ASSERT(test_file("fichier7", -1) == 0);
	CU_ASSERT(test_file("fichier8", 12) == 1);
}
/* test unitaire de fill_file_grid*/
void test_fill_file_grid(void)
{
	grid grille1, grille2, grille3, grille4;
	
	grille1 = init_grid(0);
	grille2 = init_grid(1);
	grille3 = init_grid(12);
	grille4 = init_grid(24);

	fill_file_grid("a1", "b1", &grille1);
	fill_file_grid("a2", "b2", &grille2);
	fill_file_grid("a3", "b3", &grille3);
	fill_file_grid("a4", "b4", &grille4);

	CU_ASSERT(test_grid_file("a1", &grille1) == 1);
	CU_ASSERT(test_grid_file("a2", &grille2) == 1);
	CU_ASSERT(test_grid_file("a3", &grille3) == 1);
	CU_ASSERT(test_grid_file("a4", &grille4) == 1);

	free_grid(&grille1);
	free_grid(&grille2);
	free_grid(&grille3);
	free_grid(&grille4);
}
/* test unitaire de la fonction set_grid*/
void test_set_grid(void)
{

	grid grille1, grille2, grille3, grille4;
		
	grille1 = init_grid(4);
	grille2 = init_grid(1);
	grille3 = init_grid(10);
	grille4 = init_grid(20);
	
	set_grid(&grille1, 0, 0, 'B');
	set_grid(&grille1, 3, 3, 'G');
	set_grid(&grille1, 3, 1, 'V');
		
	set_grid(&grille2, 0, 0, 'G');
	
	set_grid(&grille3, 9, 8, 'B');
	set_grid(&grille3, 7, 3, 'G');
	set_grid(&grille3, 4, 5, 'V');
	
	set_grid(&grille4, 19, 18, 'B');
	set_grid(&grille4, 15, 14, 'G');
	set_grid(&grille4, 12, 10, 'V');
	
	CU_ASSERT(grille1.array[0][0]=='B');
	CU_ASSERT(grille1.array[3][3]=='G');
	CU_ASSERT(grille1.array[3][1]=='V');
	
	CU_ASSERT(grille2.array[0][0]=='G');
	
	CU_ASSERT(grille3.array[9][8]=='B');
	CU_ASSERT(grille3.array[7][3]=='G');
	CU_ASSERT(grille3.array[4][5]=='V');
	
	CU_ASSERT(grille4.array[19][18]=='B');
	CU_ASSERT(grille4.array[15][14]=='G');
	CU_ASSERT(grille4.array[12][10]=='V');
	
	free_grid(&grille1);
	free_grid(&grille2);
	free_grid(&grille3);
	free_grid(&grille4);
}

/*	fonction pour tester si la composante 4-connexe définie dans le tableau belong de la grille 
	passée en paramètre correspond à celle définie dans le fichier name_file.
	On ouvre le fichier et on le parcourt à la fois qu'on parcourt la grille en comparant les cases du tableau
	belong avec les caractères du fichier.
	On ferme le fichier à la fin.
	La fonction retourne 1 si les composantes 4-connexes sont les mêmes et 0 sinon.*/
int test_is_tache(grid *grille, char name_file[])
{
	int test = 1;
	int i, j;
	FILE *f = fopen(name_file, "r");
	char a;
	
	for(i = 0; i < grille->size; i = i+1)
	{
		for(j = 0; j < grille->size; j = j+1)
		{
			fread(&a, sizeof(char), 1, f);
			if(grille->belong[i][j] != atoi(&a))
			{
				test = 0;
			}
		}
	}
	
	fclose(f);
	
	return test;

}

/*test unitaire de la fonction detect_flood*/
void test_detect_flood(void)
{
	grid grille1, grille2, grille3, grille4;

	grille1 = allocate_grid(1);
	grille2 = allocate_grid(4);
	grille3 = allocate_grid(5);
	grille4 = allocate_grid(10);
	
	init_grid_file("grille1", &grille1);
	init_grid_file("grille2", &grille2);
	init_grid_file("grille3", &grille3);
	init_grid_file("grille4", &grille4);
	
	detect_flood(&grille1, 0, 0, grille1.array[0][0]);
	detect_flood(&grille2, 0, 0, grille2.array[0][0]);
	detect_flood(&grille3, 0, 0, grille3.array[0][0]);
	detect_flood(&grille4, 0, 0, grille4.array[0][0]);
	
	CU_ASSERT(test_is_tache(&grille1, "belong1") == 1);
	CU_ASSERT(test_is_tache(&grille2, "belong2") == 1);
	CU_ASSERT(test_is_tache(&grille3, "belong3") == 1);
	CU_ASSERT(test_is_tache(&grille4, "belong4") == 1);

	free_grid(&grille1);
	free_grid(&grille2);
	free_grid(&grille3);
	free_grid(&grille4);
}

int test_change_color_tache(grid *grille, char c)
{
	int test = 1;
	int i, j;
	
	for(i = 0; i < grille->size; i = i+1){
		for(j = 0; j < grille->size; j = j+1){
			if(grille->belong[i][j] == 1){
				if(grille->array[i][j] != c){
					test = 0;
				}
			}
		}
	}
	
	return test;
}

/*test unitaire de la fonction change_color*/
void test_change_color(void)
{
	grid grille1, grille2, grille3, grille4;
	
	grille1 = allocate_grid(1);
	grille2 = allocate_grid(4);
	grille3 = allocate_grid(5);
	grille4 = allocate_grid(10);
	
	init_grid_file("grille1", &grille1);
	init_grid_file("grille2", &grille2);
	init_grid_file("grille3", &grille3);
	init_grid_file("grille4", &grille4);
	
	detect_flood(&grille1, 0, 0, grille1.array[0][0]);
	detect_flood(&grille2, 0, 0, grille2.array[0][0]);
	detect_flood(&grille3, 0, 0, grille3.array[0][0]);
	detect_flood(&grille4, 0, 0, grille4.array[0][0]);
	
	change_color(&grille1, 'V');
	change_color(&grille2, 'G');
	change_color(&grille3, 'J');
	change_color(&grille4, 'M');
	
	CU_ASSERT(test_change_color_tache(&grille1, 'V') == 1);
	CU_ASSERT(test_change_color_tache(&grille2, 'G') == 1);
	CU_ASSERT(test_change_color_tache(&grille3, 'J') == 1);
	CU_ASSERT(test_change_color_tache(&grille4, 'M') == 1);
	 	
	free_grid(&grille1);
	free_grid(&grille2);
	free_grid(&grille3);
	free_grid(&grille4);
}

/*test unitaire de la fonction test_same_colour*/
void test_test_same_colour(void)
{

	grid grille;
	grid grille2;
	
	grille = allocate_grid(3);
	grille2 = init_grid(3);
	init_grid_file("same_color", &grille);
	
	CU_ASSERT(test_same_colour(&grille) == 1);
	CU_ASSERT(test_same_colour(&grille2) == 0);
	
	free_grid(&grille);
	free_grid(&grille2);
}
