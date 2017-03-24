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
}

/***************** tests pour le solveur ************************/



