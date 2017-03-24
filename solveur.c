#include <stdbool.h>
#include <stdlib.h>
#include "grid_color.h"
#include "solveur.h"


grid copy(grid g){
  int n=g.size;
  grid g1=init_grid(g.size);
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      g1.array[i][j]=g.array[i][j];
    }
  }
  return g1;
}

bool choixpertinent(grid g,char c){
  if(g.array[0][0]==c)
    return false;

    int n=g.size;
  detect_flood(&g,0,0,g.array[0][0]);
  grid g1=copy(g);
  change_color(&g1,c);
  detect_flood(&g1,0,0,g.array[0][0]);
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if(g1.belong[i][j]!=g.belong[i][j]) return false;
    }
  }
  return true;
}
