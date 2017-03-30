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
	pop(&p3);
	pop(&p3);
	pop(&p3);
	pop(&p3);
	pop(&p3);

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

	push(&p2, 'V');
	push(&p2, 'G');
	push(&p2, 'R');
	push(&p2, 'V');
	push(&p2, 'G');
	push(&p2, 'R');
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
	push(&p3, 'R');
	push(&p3, 'G');
	push(&p3, 'v');
	push(&p3, 'B');
	push(&p3, 'G');
	push(&p3, 'H');
	push(&p3, 'C');
	push(&p3, 'I');
	push(&p3, 'R');
	push(&p3, 'G');
	push(&p3, 'v');
	push(&p3, 'B');
	push(&p3, 'G');
	push(&p3, 'H');
	push(&p3, 'C');
	push(&p3, 'I');

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

	push(&p2, 'H');
	push(&p2, 'H');
	push(&p2, 'H');
	push(&p2, 'H');
	push(&p2, 'H');
	push(&p2, 'I');

	push(&p3, 'J');
	push(&p3, 'J');
	push(&p3, 'J');
	push(&p3, 'J');
	push(&p3, 'K');
	push(&p3, 'J');
	push(&p3, 'J');
	push(&p3, 'J');
	push(&p3, 'J');
	push(&p3, 'J');
	push(&p3, 'L');
	pop(&p3);
	pop(&p3);
	pop(&p3);
	pop(&p3);
	pop(&p3);
	pop(&p3);
			
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

	push(&p2, 'H');
	push(&p2, 'H');
	push(&p2, 'H');
	push(&p2, 'H');
	push(&p2, 'H');
	push(&p2, 'I');

	push(&p3, 'J');
	push(&p3, 'J');
	push(&p3, 'J');
	push(&p3, 'J');
	push(&p3, 'K');
	push(&p3, 'J');
	push(&p3, 'J');
	push(&p3, 'J');
	push(&p3, 'J');
	push(&p3, 'J');
	push(&p3, 'L');
	pop(&p3);
	pop(&p3);
	pop(&p3);
	pop(&p3);
	pop(&p3);
	pop(&p3);

	CU_ASSERT(get_next(p1) == NULL);
	CU_ASSERT(get_next(p2) != NULL);
	CU_ASSERT(get_next(p3) != NULL);

	free_pile(&p1);
	free_pile(&p2);
	free_pile(&p3);

}

/***************** tests pour le solveur ************************/



