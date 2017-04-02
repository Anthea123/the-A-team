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
	pile* p4 = init_pile();
	pile* p5 = init_pile();

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

	p4 = get_next(p2);
	p5 = get_next(p3);

	CU_ASSERT(get_head(p4) == 'H');
	CU_ASSERT(get_head(p5) == 'J');

	free_pile(&p1);
	free_pile(&p2);
	free_pile(&p3);

}

void test_pilelen(void){
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

	CU_ASSERT(pilelen(p1) == 0);
	CU_ASSERT(pilelen(p2) == 7);
	CU_ASSERT(pilelen(p3) == 6);

	free_pile(&p1);
	free_pile(&p2);
	free_pile(&p3);
}

/******************tests pour les piles de piles*****************/

void test_init_solvpile(void){

	solvpile* sp1 = init_solvpile();
	solvpile* sp2 = init_solvpile();
	solvpile* sp3 = init_solvpile();

	CU_ASSERT(sp1 == NULL);
	CU_ASSERT(sp2 == NULL);
	CU_ASSERT(sp3 == NULL);
}

void test_solvest_vide(void){

	solvpile* sp1 = init_solvpile();
	solvpile* sp2 = init_solvpile();
	solvpile* sp3 = init_solvpile();

	pile* p1 = init_pile();
	pile* p2 = init_pile();
	pile* p3 = init_pile();

	push(&p1, 'R');
	push(&p1, 'R');
	push(&p1, 'R');
	push(&p1, 'R');

	push(&p2, 'V');
	push(&p2, 'V');
	push(&p2, 'V');

	push(&p3, 'G');
	push(&p3, 'G');

	solvpush(&sp2, p1);

	solvpush(&sp3, p2);
	solvpush(&sp3, p3);
	solvpop(&sp3);
	solvpop(&sp3);

	CU_ASSERT(solvest_vide(sp1) == true);
	CU_ASSERT(solvest_vide(sp2) == false);
	CU_ASSERT(solvest_vide(sp3) == true);

	free_pile(&p1);
	free_pile(&p2);
	free_pile(&p3);

	free_solvpile(&sp1);
	free_solvpile(&sp2);
	free_solvpile(&sp3);
}

bool compare_piles(pile *p1, pile *p2){

	if(pilelen(p1) != pilelen(p2)){
		return false;
	}
	else{
		while(!est_vide(p1)){
			if(get_head(p1) != get_head(p2)){
				return false;
			}
			p1 = get_next(p1);
			p2 = get_next(p2);
		}
	}

	return true;
}

void test_solvpush(void){
	solvpile* sp1 = init_solvpile();
	solvpile* sp2 = init_solvpile();
	solvpile* sp3 = init_solvpile();
	solvpile* sp4 = init_solvpile();

	pile* p1 = init_pile();
	pile* p2 = init_pile();
	pile* p3 = init_pile();
	pile* p4 = init_pile();

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

	solvpush(&sp1, p1);
	solvpush(&sp2, p2);
	solvpush(&sp3, p2);
	solvpush(&sp3, p3);
	solvpush(&sp4, p4);

	CU_ASSERT(compare_piles(solvget_head(sp1), p1) == true);
	CU_ASSERT(compare_piles(solvget_head(sp2), p2) == true);
	CU_ASSERT(compare_piles(solvget_head(sp3), p3) == true);
	CU_ASSERT(solvest_vide(sp4) == true);

	free_pile(&p1);
	free_pile(&p2);
	free_pile(&p3);
	free_pile(&p4);

	free_solvpile(&sp1);
	free_solvpile(&sp2);
	free_solvpile(&sp3);
	free_solvpile(&sp4);
}

void test_solvpop(void){

	solvpile* sp1 = init_solvpile();
	solvpile* sp2 = init_solvpile();
	solvpile* sp3 = init_solvpile();

	pile* p1 = init_pile();
	pile* p2 = init_pile();
	pile* p3 = init_pile();
	pile* p4 = init_pile();
	pile* p5 = init_pile();
	pile* p6 = init_pile();
	pile* p7 = init_pile();
	pile* p8 = init_pile();
	pile* p9 = init_pile();
	pile* p10 = init_pile();
	pile* p11 = init_pile();
	pile* p12 = init_pile();
	pile* p13 = init_pile();
	pile* p14 = init_pile();
	pile* p15 = init_pile();

	push(&p1, 'G');

	push(&p2, 'V');
	push(&p2, 'G');
	push(&p2, 'R');
	
	push(&p3, 'R');
	push(&p3, 'G');
	push(&p3, 'v');

	push(&p4, 'B');
	push(&p4, 'G');

	push(&p5, 'H');
	push(&p5, 'C');
	push(&p5, 'I');

	push(&p6, 'G');

	push(&p7, 'V');
	push(&p7, 'G');
	push(&p7, 'R');
	
	push(&p8, 'R');
	push(&p8, 'G');
	push(&p8, 'v');

	push(&p9, 'B');
	push(&p9, 'G');

	push(&p10, 'H');
	push(&p10, 'C');
	push(&p10, 'I');

	push(&p11, 'G');

	push(&p12, 'V');
	push(&p12, 'G');
	push(&p12, 'R');
	
	push(&p13, 'R');
	push(&p13, 'G');
	push(&p13, 'v');

	push(&p14, 'B');
	push(&p14, 'G');

	push(&p15, 'H');
	push(&p15, 'C');
	push(&p15, 'I');

	solvpush(&sp1, p1);
	solvpop(&sp1);

	solvpush(&sp2, p2);
	solvpush(&sp2, p3);
	solvpush(&sp2, p4);
	solvpush(&sp2, p5);
	solvpop(&sp2);

	solvpush(&sp3, p6);
	solvpush(&sp3, p7);
	solvpush(&sp3, p8);
	solvpush(&sp3, p9);
	solvpush(&sp3, p10);
	solvpush(&sp3, p11);
	solvpush(&sp3, p12);
	solvpush(&sp3, p13);
	solvpush(&sp3, p14);
	solvpush(&sp3, p15);
	
	for(int i = 0; i < 8; i = i+1){
		solvpop(&sp3);
	}

	CU_ASSERT(solvest_vide(sp1) == true);
	CU_ASSERT(compare_piles(solvget_head(sp2), p4) == true);
	CU_ASSERT(compare_piles(solvget_head(sp3), p7) == true);
	

	free_pile(&p1);
	free_pile(&p2);
	free_pile(&p3);
	free_pile(&p4);
	free_pile(&p5);
	free_pile(&p6);
	free_pile(&p7);
	free_pile(&p8);
	free_pile(&p9);
	free_pile(&p10);
	free_pile(&p11);
	free_pile(&p12);
	free_pile(&p13);
	free_pile(&p14);
	free_pile(&p15);

	free_solvpile(&sp1);
	free_solvpile(&sp2);
	free_solvpile(&sp3);
}

void test_free_solvpile(void){
	solvpile* sp1 = init_solvpile();
	solvpile* sp2 = init_solvpile();
	solvpile* sp3 = init_solvpile();

	pile* p1 = init_pile();
	pile* p2 = init_pile();
	pile* p3 = init_pile();
	pile* p4 = init_pile();
	pile* p5 = init_pile();
	pile* p6 = init_pile();
	pile* p7 = init_pile();
	pile* p8 = init_pile();
	pile* p9 = init_pile();
	pile* p10 = init_pile();
	pile* p11 = init_pile();
	pile* p12 = init_pile();
	pile* p13 = init_pile();
	pile* p14 = init_pile();
	pile* p15 = init_pile();

	push(&p1, 'G');

	push(&p2, 'V');
	push(&p2, 'G');
	push(&p2, 'R');
	
	push(&p3, 'R');
	push(&p3, 'G');
	push(&p3, 'v');

	push(&p4, 'B');
	push(&p4, 'G');

	push(&p5, 'H');
	push(&p5, 'C');
	push(&p5, 'I');

	push(&p6, 'G');

	push(&p7, 'V');
	push(&p7, 'G');
	push(&p7, 'R');
	
	push(&p8, 'R');
	push(&p8, 'G');
	push(&p8, 'v');

	push(&p9, 'B');
	push(&p9, 'G');

	push(&p10, 'H');
	push(&p10, 'C');
	push(&p10, 'I');

	push(&p11, 'G');

	push(&p12, 'V');
	push(&p12, 'G');
	push(&p12, 'R');
	
	push(&p13, 'R');
	push(&p13, 'G');
	push(&p13, 'v');

	push(&p14, 'B');
	push(&p14, 'G');

	push(&p15, 'H');
	push(&p15, 'C');
	push(&p15, 'I');

	solvpush(&sp1, p1);
	solvpop(&sp1);

	solvpush(&sp2, p2);
	solvpush(&sp2, p3);
	solvpush(&sp2, p4);
	solvpush(&sp2, p5);
	solvpop(&sp2);

	solvpush(&sp3, p6);
	solvpush(&sp3, p7);
	solvpush(&sp3, p8);
	solvpush(&sp3, p9);
	solvpush(&sp3, p10);
	solvpush(&sp3, p11);
	solvpush(&sp3, p12);
	solvpush(&sp3, p13);
	solvpush(&sp3, p14);
	solvpush(&sp3, p15);
	
	for(int i = 0; i < 8; i = i+1){
		solvpop(&sp3);
	}

	free_solvpile(&sp1);
	free_solvpile(&sp2);
	free_solvpile(&sp3);

	CU_ASSERT(solvest_vide(sp1) == true);
	CU_ASSERT(solvest_vide(sp2) == true);
	CU_ASSERT(solvest_vide(sp3) == true);

	free_pile(&p1);
	free_pile(&p2);
	free_pile(&p3);
	free_pile(&p4);
	free_pile(&p5);
	free_pile(&p6);
	free_pile(&p7);
	free_pile(&p8);
	free_pile(&p9);
	free_pile(&p10);
	free_pile(&p11);
	free_pile(&p12);
	free_pile(&p13);
	free_pile(&p14);
	free_pile(&p15);
}

void test_solvget_head(void){
	solvpile* sp1 = init_solvpile();
	solvpile* sp2 = init_solvpile();
	solvpile* sp3 = init_solvpile();

	pile* p1 = init_pile();
	pile* p2 = init_pile();
	pile* p3 = init_pile();
	pile* p4 = init_pile();
	pile* p5 = init_pile();
	pile* p6 = init_pile();
	pile* p7 = init_pile();
	pile* p8 = init_pile();
	pile* p9 = init_pile();
	pile* p10 = init_pile();
	pile* p11 = init_pile();
	pile* p12 = init_pile();
	pile* p13 = init_pile();
	pile* p14 = init_pile();
	pile* p15 = init_pile();

	push(&p1, 'G');

	push(&p2, 'V');
	push(&p2, 'G');
	push(&p2, 'R');
	
	push(&p3, 'R');
	push(&p3, 'G');
	push(&p3, 'v');
	push(&p3, 'T');
	push(&p3, 'G');
	push(&p3, 'Z');
	push(&p3, 'U');
	push(&p3, 'A');
	push(&p3, 'l');

	push(&p4, 'B');
	push(&p4, 'G');

	push(&p5, 'H');
	push(&p5, 'C');
	push(&p5, 'I');

	push(&p6, 'G');

	push(&p7, 'V');
	push(&p7, 'G');
	push(&p7, 'R');
	
	push(&p8, 'R');
	push(&p8, 'G');
	push(&p8, 'v');

	push(&p9, 'B');
	push(&p9, 'G');

	push(&p10, 'H');
	push(&p10, '2');
	push(&p10, 'Y');
	push(&p10, 'd');
	push(&p10, 'J');
	push(&p10, 'U');
	push(&p10, 'W');
	push(&p10, 'u');
	push(&p10, 'r');

	push(&p11, 'G');

	push(&p12, 'V');
	push(&p12, 'G');
	push(&p12, 'R');
	
	push(&p13, 'R');
	push(&p13, 'G');
	push(&p13, 'v');

	push(&p14, 'B');
	push(&p14, 'G');

	push(&p15, 'H');
	push(&p15, 'C');
	push(&p15, 'I');

	solvpush(&sp1, p1);
	solvpop(&sp1);

	solvpush(&sp2, p2);
	solvpush(&sp2, p3);
	solvpush(&sp2, p4);
	solvpush(&sp2, p5);
	solvpop(&sp2);
	solvpop(&sp2);

	solvpush(&sp3, p6);
	solvpush(&sp3, p7);
	solvpush(&sp3, p8);
	solvpush(&sp3, p9);
	solvpush(&sp3, p10);
	solvpush(&sp3, p11);
	solvpush(&sp3, p12);
	solvpush(&sp3, p13);
	solvpush(&sp3, p14);
	solvpush(&sp3, p15);
	
	for(int i = 0; i < 5; i = i+1){
		solvpop(&sp3);
	}
			
	CU_ASSERT(solvget_head(sp1) == NULL);
	CU_ASSERT(compare_piles(solvget_head(sp2), p3) == true);
	CU_ASSERT(compare_piles(solvget_head(sp3), p10) == true);

	free_pile(&p1);
	free_pile(&p2);
	free_pile(&p3);
	free_pile(&p4);
	free_pile(&p5);
	free_pile(&p6);
	free_pile(&p7);
	free_pile(&p8);
	free_pile(&p9);
	free_pile(&p10);
	free_pile(&p11);
	free_pile(&p12);
	free_pile(&p13);
	free_pile(&p14);
	free_pile(&p15);

	free_solvpile(&sp1);
	free_solvpile(&sp2);
	free_solvpile(&sp3);
}

void test_solvget_next(void){
	solvpile* sp1 = init_solvpile();
	solvpile* sp2 = init_solvpile();
	solvpile* sp3 = init_solvpile();

	pile* p1 = init_pile();
	pile* p2 = init_pile();
	pile* p3 = init_pile();
	pile* p4 = init_pile();
	pile* p5 = init_pile();
	pile* p6 = init_pile();
	pile* p7 = init_pile();
	pile* p8 = init_pile();
	pile* p9 = init_pile();
	pile* p10 = init_pile();
	pile* p11 = init_pile();
	pile* p12 = init_pile();
	pile* p13 = init_pile();
	pile* p14 = init_pile();
	pile* p15 = init_pile();

	push(&p1, 'G');

	push(&p2, 'V');
	push(&p2, 'G');
	push(&p2, 'R');
	
	push(&p3, 'R');
	push(&p3, 'G');
	push(&p3, 'v');
	push(&p3, 'T');
	push(&p3, 'G');
	push(&p3, 'Z');
	push(&p3, 'U');
	push(&p3, 'A');
	push(&p3, 'l');

	push(&p4, 'B');
	push(&p4, 'G');

	push(&p5, 'H');
	push(&p5, 'C');
	push(&p5, 'I');

	push(&p6, 'G');

	push(&p7, 'V');
	push(&p7, 'G');
	push(&p7, 'R');
	
	push(&p8, 'R');
	push(&p8, 'G');
	push(&p8, 'v');

	push(&p9, 'B');
	push(&p9, 'G');

	push(&p10, 'H');
	push(&p10, '2');
	push(&p10, 'Y');
	push(&p10, 'd');
	push(&p10, 'J');
	push(&p10, 'U');
	push(&p10, 'W');
	push(&p10, 'u');
	push(&p10, 'r');

	push(&p11, 'G');

	push(&p12, 'V');
	push(&p12, 'G');
	push(&p12, 'R');
	
	push(&p13, 'R');
	push(&p13, 'G');
	push(&p13, 'v');

	push(&p14, 'B');
	push(&p14, 'G');

	push(&p15, 'H');
	push(&p15, 'C');
	push(&p15, 'I');

	solvpush(&sp1, p1);
	solvpop(&sp1);

	solvpush(&sp2, p2);
	solvpush(&sp2, p3);
	solvpush(&sp2, p4);
	solvpush(&sp2, p5);
	solvpop(&sp2);

	solvpush(&sp3, p6);
	solvpush(&sp3, p7);
	solvpush(&sp3, p8);
	solvpush(&sp3, p9);
	solvpush(&sp3, p10);
	solvpush(&sp3, p11);
	solvpush(&sp3, p12);
	solvpush(&sp3, p13);
	solvpush(&sp3, p14);
	solvpush(&sp3, p15);
	
	for(int i = 0; i < 9; i = i+1){
		solvpop(&sp3);
	}

	CU_ASSERT(solvget_next(sp1) == NULL);
	CU_ASSERT(solvget_next(sp2) != NULL);
	CU_ASSERT(solvget_next(sp3) == NULL);

	CU_ASSERT(compare_piles(solvget_head(solvget_next(sp2)), p3) == true);

	free_pile(&p1);
	free_pile(&p2);
	free_pile(&p3);
	free_pile(&p4);
	free_pile(&p5);
	free_pile(&p6);
	free_pile(&p7);
	free_pile(&p8);
	free_pile(&p9);
	free_pile(&p10);
	free_pile(&p11);
	free_pile(&p12);
	free_pile(&p13);
	free_pile(&p14);
	free_pile(&p15);

	free_solvpile(&sp1);
	free_solvpile(&sp2);
	free_solvpile(&sp3);
}

void test_minpile(void){
	solvpile* sp1 = init_solvpile();
	solvpile* sp2 = init_solvpile();
	solvpile* sp3 = init_solvpile();

	pile* p1 = init_pile();
	pile* p2 = init_pile();
	pile* p3 = init_pile();
	pile* p4 = init_pile();
	pile* p5 = init_pile();
	pile* p6 = init_pile();
	pile* p7 = init_pile();
	pile* p8 = init_pile();
	pile* p9 = init_pile();
	pile* p10 = init_pile();
	pile* p11 = init_pile();
	pile* p12 = init_pile();
	pile* p13 = init_pile();
	pile* p14 = init_pile();
	pile* p15 = init_pile();

	push(&p1, 'G');

	push(&p2, 'V');
	push(&p2, 'G');
	
	push(&p3, 'R');
	push(&p3, 'G');
	push(&p3, 'v');

	push(&p4, 'B');
	push(&p4, 'G');

	push(&p5, 'H');
	push(&p5, 'C');
	push(&p5, 'I');

	push(&p6, 'G');
	push(&p6, 'G');
	push(&p6, 'G');
	push(&p6, 'G');
	push(&p6, 'G');

	push(&p7, 'V');
	push(&p7, 'G');
	push(&p7, 'R');
	
	push(&p8, 'R');
	push(&p8, 'G');
	push(&p8, 'v');

	push(&p9, 'B');
	push(&p9, 'G');

	push(&p10, 'H');
	push(&p10, 'C');
	push(&p10, 'I');

	push(&p11, 'G');

	push(&p12, 'V');
	push(&p12, 'G');
	push(&p12, 'R');
	
	push(&p13, 'R');
	push(&p13, 'G');
	push(&p13, 'v');

	push(&p14, 'B');
	push(&p14, 'G');

	push(&p15, 'H');
	push(&p15, 'C');
	push(&p15, 'I');

	solvpush(&sp1, p1);
	solvpop(&sp1);

	solvpush(&sp2, p2);
	solvpush(&sp2, p3);
	solvpush(&sp2, p4);
	solvpush(&sp2, p5);

	solvpush(&sp3, p6);
	solvpush(&sp3, p7);
	solvpush(&sp3, p8);
	solvpush(&sp3, p9);
	solvpush(&sp3, p10);
	solvpush(&sp3, p11);
	solvpush(&sp3, p12);
	solvpush(&sp3, p13);
	solvpush(&sp3, p14);
	solvpush(&sp3, p15);

	CU_ASSERT(minpile(sp1) == NULL);
	CU_ASSERT(compare_piles(minpile(sp2), p4) == true);
	CU_ASSERT(compare_piles(minpile(sp3), p11) == true);

	free_pile(&p1);
	free_pile(&p2);
	free_pile(&p3);
	free_pile(&p4);
	free_pile(&p5);
	free_pile(&p6);
	free_pile(&p7);
	free_pile(&p8);
	free_pile(&p9);
	free_pile(&p10);
	free_pile(&p11);
	free_pile(&p12);
	free_pile(&p13);
	free_pile(&p14);
	free_pile(&p15);

	free_solvpile(&sp1);
	free_solvpile(&sp2);
	free_solvpile(&sp3);
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
					/*printf("%d, %d: %c, %c; %d, %d\n", i, j, g1.array[i][j], g2.array[i][j], g1.belong[i][j], g2.belong[i][j]);*/
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


