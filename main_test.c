#include "grid_color.h"
#include "solveur.h"
#include "CUnit/CUnit.h"
#include "CUnit/Basic.h"
#include "unit_test.h"

int main(){
    CU_initialize_registry();

	CU_pSuite suite1 = CU_add_suite("piles", 0, 0);
    /*CU_pSuite suite2 = CU_add_suite("solveur", 0, 0);*/

    CU_add_test(suite1, "init_pile", test_init_pile);
    CU_add_test(suite1, "est_vide", test_est_vide);

    CU_basic_set_mode(CU_BRM_VERBOSE);
	CU_basic_run_tests();
	CU_cleanup_registry();

	return 0;
}