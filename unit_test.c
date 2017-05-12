#include "CUnit/CUnit.h"
#include "CUnit/Basic.h"
#include "unit_test.h"

void test_choixpertinent(void){

	char couleurs[6] = {'B', 'V', 'G', 'R', 'M', 'Y'}; 

	grid g1 = init_grid(4);
	grid g2 = init_grid(12);
	grid g3 = init_grid(20);

	detect_flood(&g1, 0, 0, g1.array[0][0]);
	detect_flood(&g2, 0, 0, g2.array[0][0]);
	detect_flood(&g3, 0, 0, g3.array[0][0]);

	int compteur_g1 = compteur(g1);
	int compteur_g2 = compteur(g2);
	int compteur_g3 = compteur(g3);

	for(int i = 0; i < 6; i = i+1){
		if(choixpertinent(g1, couleurs[i])){
			grid g1_bis = copy(g1);
			
			CU_ASSERT(couleurs[i] != g1.array[0][0]);

			change_color(&g1_bis, couleurs[i]);
			refresh_grid(&g1_bis);
			detect_flood(&g1_bis, 0, 0, g1_bis.array[0][0]);

			CU_ASSERT(compteur(g1_bis) >= compteur_g1);

			free_grid(&g1_bis);
		}

		if(choixpertinent(g2, couleurs[i])){
			grid g2_bis = copy(g2);
			
			CU_ASSERT(couleurs[i] != g2.array[0][0]);

			change_color(&g2_bis, couleurs[i]);
			refresh_grid(&g2_bis);
			detect_flood(&g2_bis, 0, 0, g2_bis.array[0][0]);

			CU_ASSERT(compteur(g2_bis) >= compteur_g2);

			free_grid(&g2_bis);
		}

		if(choixpertinent(g3, couleurs[i])){
			grid g3_bis = copy(g3);
			
			CU_ASSERT(couleurs[i] != g3.array[0][0]);

			change_color(&g3_bis, couleurs[i]);
			refresh_grid(&g3_bis);
			detect_flood(&g3_bis, 0, 0, g3_bis.array[0][0]);

			CU_ASSERT(compteur(g3_bis) >= compteur_g3);

			free_grid(&g3_bis);
		}
	}

	free_grid(&g1);
	free_grid(&g2);
	free_grid(&g3);
}