#include "solveur.h"
#include "grid_color.h"
int main(){
  grid g1=init_grid(10);
  grid g2=copy(g1);
  grid_print(&g1);
  printf("\n");
  grid_print(&g2);
  printf("%d",choixpertinent(g1,'R'));
}
