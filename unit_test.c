#include "CUnit/CUnit.h"
#include "CUnit/Basic.h"
#include "unit_test.h"
#include "pile.h"

/***************** tests pour les piles *************************/

void test_init_pile(void){

	pile* p1 = init_pile();
	pile* p2 = init_pile();
	pile* p3 = init_pile();

	CU_ASSERT(p1 == NULL);
	CU_ASSERT(p2 == NULL);
	CU_ASSERT(p3 == NULL);
}

void test_est_vide(void){

	pile* p1 = init_pile();
	pile* p2 = init_pile();
	pile* p3 = init_pile();

	push(&p2, 'V');
	push(&p2, 'V');
	push(&p2, 'V');

	push(&p3, 'G');
	push(&p3, 'G');
	pop(&p3);
	pop(&p3);

	CU_ASSERT(est_vide(p1) == true);
	CU_ASSERT(est_vide(p2) == false);
	CU_ASSERT(est_vide(p3) == true);

	free_pile(&p1);
	free_pile(&p2);
	free_pile(&p3);
}

void test_push(void){
	pile* p1 = init_pile();
	pile* p2 = init_pile();
	pile* p3 = init_pile();

	push(&p1, 'G');

	push(&p2, 'V');
	push(&p2, 'G');
	push(&p2, 'R');
	
	push(&p3, 'R');
	push(&p3, 'G');
	push(&p3, 'v');
	push(&p3, 'B');
	push(&p3, 'G');
	push(&p3, 'H');
	push(&p3, 'C');
	push(&p3, 'I');

	CU_ASSERT(get_head(p1) == 'G');
	CU_ASSERT(get_head(p2) == 'R');
	CU_ASSERT(get_head(p3) == 'I');

	free_pile(&p1);
	free_pile(&p2);
	free_pile(&p3);
}

void test_pop(void){
	pile* p1 = init_pile();
	pile* p2 = init_pile();
	pile* p3 = init_pile();

	push(&p1, 'G');
	pop(&p1);

	push(&p2, 'V');
	push(&p2, 'G');
	push(&p2, 'R');
	pop(&p2);
	
	push(&p3, 'R');
	push(&p3, 'G');
	push(&p3, 'v');
	push(&p3, 'B');
	push(&p3, 'G');
	push(&p3, 'H');
	push(&p3, 'C');
	push(&p3, 'I');

	for(int i = 0; i <= 4; i = i+1){
		pop(&p3);
	}

	CU_ASSERT(est_vide(p1) == true);
	CU_ASSERT(get_head(p2) == 'G');
	CU_ASSERT(get_head(p3) == 'v');

	free_pile(&p1);
	free_pile(&p2);
	free_pile(&p3);
}

void test_free_pile(void){
	pile* p1 = init_pile();
	pile* p2 = init_pile();
	pile* p3 = init_pile();

	for(int i = 0; i <= 5; i = i+1){
		push(&p2, 'H');
	}

	for(int i = 0; i <= 200; i = i+1){
		push(&p3, 'R');
	}

	free_pile(&p1);
	free_pile(&p2);
	free_pile(&p3);

	CU_ASSERT(est_vide(p1) == true);
	CU_ASSERT(est_vide(p2) == true);
	CU_ASSERT(est_vide(p3) == true);
}

void test_get_head(void){
	pile* p1 = init_pile();
	pile* p2 = init_pile();
	pile* p3 = init_pile();

	for(int i = 0; i <= 5; i = i+1){
		push(&p2, 'H');
	}
	
	push(&p2, 'I');

	for(int i = 0; i <= 4; i = i+1){
		push(&p3, 'J');
	}
	push(&p3, 'K');
	for(int i = 0; i <= 6; i = i+1){
		push(&p3, 'J');
	}
	push(&p3, 'L');
	
	CU_ASSERT(get_head(p3) == 'L');
	
	for(int i = 0; i <= 7; i = i+1){
		pop(&p3);
	}
			
	CU_ASSERT(get_head(p1) == '\0');
	CU_ASSERT(get_head(p2) == 'I');
	CU_ASSERT(get_head(p3) == 'K');

	free_pile(&p1);
	free_pile(&p2);
	free_pile(&p3);

}

void test_get_next(void){
	pile* p1 = init_pile();
	pile* p2 = init_pile();
	pile* p3 = init_pile();

	for(int i = 0; i <= 5; i = i+1){
		push(&p2, 'H');
	}
	
	push(&p2, 'I');

	for(int i = 0; i <= 4; i = i+1){
		push(&p3, 'J');
	}
	push(&p3, 'K');
	for(int i = 0; i <= 6; i = i+1){
		push(&p3, 'J');
	}
	push(&p3, 'L');
	for(int i = 0; i <= 7; i = i+1){
		pop(&p3);
	}

	CU_ASSERT(get_next(p1) == NULL);
	CU_ASSERT(get_next(p2) != NULL);
	CU_ASSERT(get_next(p3) != NULL);

	free_pile(&p1);
	free_pile(&p2);
	free_pile(&p3);

}

/***************** tests pour le solveur ************************/

bool test_egalite(grid g1, grid g2){

	if(g1.size != g2.size){
		printf("taille\n");
		return false;
	}
	else{
		for(int i = 0; i < g1.size; i = i+1){
			for(int j = 0; j < g1.size; j = j+1){
				if((g1.array[i][j] != g2.array[i][j]) || (g1.belong[i][j] != g2.belong[i][j])){
					printf("%d, %d: %c, %c; %d, %d\n", i, j, g1.array[i][j], g2.array[i][j], g1.belong[i][j], g2.belong[i][j]);
					return false;
				}
			}
		}
	}

	return true;
}

void test_copy(void){
	grid g1 = init_grid(0);
	grid g2 = copy(g1);

	grid g3 = init_grid(1);
	grid g4 = copy(g3);

	grid g5 = init_grid(12);
	grid g6 = copy(g5);

	CU_ASSERT(test_egalite(g1, g2) == true);
	CU_ASSERT(test_egalite(g3, g4) == true);
	CU_ASSERT(test_egalite(g5, g6) == true);

	free_grid(&g1);
	free_grid(&g2);
	free_grid(&g3);
	free_grid(&g4);
	free_grid(&g5);
	free_grid(&g6);
}


