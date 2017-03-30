#include <stdbool.h>
#include <stdlib.h>
#include "grid_color.h"
#include "solveur.h"
#include "pile.h"
#include "solvpile.h"

char couleurs[6]={'B','V','R','J','M','G'};

grid copy(grid g){
  int n=g.size;
  grid g1=init_grid(g.size);
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      g1.array[i][j]=g.array[i][j];
      g1.belong[i][j]=g.belong[i][j];
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
  detect_flood(&g1,0,0,g1.array[0][0]);
  change_color(&g1,c);
  refresh_grid(&g1);
  detect_flood(&g1,0,0,g1.array[0][0]);
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if(g1.belong[i][j]!=g.belong[i][j]) return true;
    }
  }
  return false;
}

solvpile* solveur(grid g,pile *solution,int prof,int profmax,solvpile* soltrouve){
    if(prof==profmax){
      solution=NULL;
      prof=0;
      return soltrouve;
    }
    for(int i=0;i<6;i++){
      if(choixpertinent(g,couleurs[i]) && prof<profmax){
        grid g2=copy(g);
        push(&solution,couleurs[i]);
        detect_flood(&g2,0,0,g.array[0][0]);
        change_color(&g2,couleurs[i]);
        refresh_grid(&g2);
        if(test_same_colour(&g2)){
          solvpush(&soltrouve,solution);
          profmax=prof;
          prof=0;
        }
        else {
          prof++;
          profmax++;
          soltrouve=solveur(g2,solution,prof,profmax,soltrouve);
        }
      }
    }
    return soltrouve;
}
