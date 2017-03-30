#include<stdio.h>
#include<stdlib.h>
#include "solveur.h"
#include "grid_color.h"
#include "pile.h"
#include "solvpile.h"
int main(){
  grid g1=init_grid(10);
  grid_print(&g1);
  printf("\n");
  pile *solution=NULL;
  solvpile *soltrouve=NULL;
  soltrouve=solveur(g1,solution,0,1,soltrouve);
  print_pile(minpile(soltrouve));

}
