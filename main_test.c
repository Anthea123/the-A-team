#include "grid_color.h"
#include "solveur.h"
#include "CUnit/CUnit.h"
#include "CUnit/Basic.h"
#include "unit_test.h"

int main(){
    CU_initialize_registry();

	CU_pSuite suite1 = CU_add_suite("NArbres", 0, 0);
    //CU_pSuite suite2 = CU_add_suite("solveur", 0, 0);

/***************** tests pour les NArbres *************************/

    CU_add_test(suite1, "nouvel_NArbre", test_nouvelNArbre);
    CU_add_test(suite1, "ajoutFils", test_ajoutFils);

    CU_basic_set_mode(CU_BRM_VERBOSE);
	CU_basic_run_tests();
	CU_cleanup_registry();

	return 0;
}