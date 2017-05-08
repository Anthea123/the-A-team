#include "CUnit/CUnit.h"
#include "CUnit/Basic.h"
#include "unit_test.h"
#include "grid_tree.h"


/***************** tests pour les NArbres *************************/

bool test_egalite(grid g1, grid g2){

	if(g1.size != g2.size){
		printf("taille\n");
		return false;
	}
	else{
		for(int i = 0; i < g1.size; i = i+1){
			for(int j = 0; j < g1.size; j = j+1){
				if((g1.array[i][j] != g2.array[i][j]) || (g1.belong[i][j] != g2.belong[i][j])){
					return false;
				}
			}
		}
	}

	return true;
}

void test_nouvelNArbre(void){

	grid g1 = init_grid(1);
	grid g2 = init_grid(5);
	grid g3 = init_grid(10);

	NArbre a1 = nouvelNArbre(g1);
	NArbre a2 = nouvelNArbre(g2);
	NArbre a3 = nouvelNArbre(g3);

	CU_ASSERT(a1 != NULL);
	CU_ASSERT(getnbFils(a1) == 0);
	CU_ASSERT(test_egalite(g1, getgrid(a1)));

	CU_ASSERT(a1 != NULL);
	CU_ASSERT(getnbFils(a1) == 0);
	CU_ASSERT(test_egalite(g2, getgrid(a2)));

	CU_ASSERT(a1 != NULL);
	CU_ASSERT(getnbFils(a1) == 0);
	CU_ASSERT(test_egalite(g3, getgrid(a3)));

	free_grid_tree(a1);
	free_grid_tree(a2);
	free_grid_tree(a3);
}

void test_ajoutFils(void){
	grid g1 = init_grid(1);
	grid g2 = init_grid(5);
	grid g3 = init_grid(10);
	grid g4 = init_grid(1);
	grid g5 = init_grid(5);
	grid g6 = init_grid(10);
	grid g7 = init_grid(1);
	grid g8 = init_grid(5);
	grid g9 = init_grid(10);
	grid g10 = init_grid(1);
	grid g11 = init_grid(5);
	grid g12 = init_grid(10);
	grid g13 = init_grid(1);
	grid g14 = init_grid(5);
	grid g15 = init_grid(10);
	grid g16 = init_grid(1);
	grid g17 = init_grid(5);
	grid g18 = init_grid(10);

	NArbre a1 = nouvelNArbre(g1);
	NArbre a2 = nouvelNArbre(g2);
	NArbre a3 = nouvelNArbre(g3);
	
	NArbre a4 = nouvelNArbre(g4);
	NArbre a5 = nouvelNArbre(g5);
	NArbre a6 = nouvelNArbre(g6);

	NArbre a7 = nouvelNArbre(g7);
	NArbre a8 = nouvelNArbre(g8);
	NArbre a9 = nouvelNArbre(g9);

	NArbre a10 = nouvelNArbre(g10);
	NArbre a11 = nouvelNArbre(g11);
	NArbre a12 = nouvelNArbre(g12);
	
	NArbre a13 = nouvelNArbre(g13);
	NArbre a14 = nouvelNArbre(g14);
	NArbre a15 = nouvelNArbre(g15);

	NArbre a16 = nouvelNArbre(g16);
	NArbre a17 = nouvelNArbre(g17);
	NArbre a18 = nouvelNArbre(g18);

	ajoutFils(a1, a4);
	ajoutFils(a1, a5);
	ajoutFils(a1, a6);

	ajoutFils(a2, a7);
	ajoutFils(a2, a8);

	ajoutFils(a3, a9);
	ajoutFils(a3, a10);
	ajoutFils(a3, a11);
	ajoutFils(a3, a12);
	ajoutFils(a3, a13);
	ajoutFils(a3, a14);
	ajoutFils(a3, a15);
	ajoutFils(a3, a16);
	ajoutFils(a3, a17);
	ajoutFils(a3, a18);
	ajoutFils(a3, a4);
	ajoutFils(a3, a5);

	CU_ASSERT(a1 != NULL);
	CU_ASSERT(getnbFils(a1) == 3);

	CU_ASSERT(a2 != NULL);
	CU_ASSERT(getnbFils(a2) == 2);

	CU_ASSERT(a3 != NULL);
	CU_ASSERT(getnbFils(a3) == 5);
	
	/*printf("****************a1*****************\n");
	print_grid_tree(a1);
	printf("****************a2*****************\n");
	print_grid_tree(a2);
	printf("****************a3*****************\n");
	print_grid_tree(a3);*/
		
	free_grid_tree(a1);
	free_grid_tree(a2);
	free_grid_tree(a3);

	/*free_grid(&g1);
	free_grid(&g2);
	free_grid(&g3);*/
}
















