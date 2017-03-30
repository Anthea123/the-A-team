#include "grid_color.h"
#include "solveur.h"
#include "CUnit/CUnit.h"
#include "CUnit/Basic.h"
#include "unit_test.h"
//#include "pile.h"

int main(){
    CU_initialize_registry();

	CU_pSuite suite1 = CU_add_suite("piles", 0, 0);
    CU_pSuite suite2 = CU_add_suite("solveur", 0, 0);

    CU_add_test(suite1, "init_pile", test_init_pile);
    CU_add_test(suite1, "est_vide", test_est_vide);
    CU_add_test(suite1, "push", test_push);
    CU_add_test(suite1, "pop", test_pop);
    CU_add_test(suite1, "free_pile", test_free_pile);
    CU_add_test(suite1, "get_head", test_get_head);
    CU_add_test(suite1, "get_next", test_get_next);
    
    CU_add_test(suite2, "copy", test_copy);

    CU_basic_set_mode(CU_BRM_VERBOSE);
	CU_basic_run_tests();
	CU_cleanup_registry();

	return 0;
}