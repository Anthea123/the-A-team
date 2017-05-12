#include "grid_color.h"
#include "solveur_rapide.h"
#include "CUnit/CUnit.h"
#include "CUnit/Basic.h"
#include "unit_test.h"

int main(){
    CU_initialize_registry();

   

   	CU_basic_set_mode(CU_BRM_VERBOSE);
	CU_basic_run_tests();
	CU_cleanup_registry();

	return 0;
}
