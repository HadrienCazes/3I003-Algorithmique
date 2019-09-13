#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main(){
  int k = 8; // nombre de type de capacité différente
  int S = 11; // on initialise directement la valeur en dg de confiture à mettre
  int V[8] = {1,2,5,10,20,50,100,200}; // capacité bocal 1dg 2 dg

  //int *nbappels = 0; // stock le nombre d'appels (modifié par la fonction algoprogdyn)

  int **M = (int**) malloc (S*sizeof(int*));
  for(int index = 0 ; index < S ; index ++){
    M[index] = (int*) malloc (k*sizeof(int));
  }
  //Remplissage tableau memoisation
  for (int i = 0 ; i < S ; i++){
    for (int j = 0 ; j < k ; j++){
      M[i][j] = -1;
    }
  }
/*  // Affichage tableau memoisation
  for (int i = 0 ; i < S ; i++){
    for (int j = 0 ; j < k ; j++){
      printf("%d ",M[i][j]);
    }
    printf("\n");
  }
*/
//  printf("\n DEBUT PROGRAMME \n");
  int val = AlgoProgDyn(S,k,V,M);
  printf("val = %d \n",val);
  //printf("NBOP = %d \n",nbappels);
/*  printf("\n FIN PROGRAMME \n");

  printf("\n");
  // Affichage tableau memoisation
  for (int i = 0 ; i < S ; i++){
    for (int j = 0 ; j < k ; j++){
      printf("%d ",M[i][j]);
    }
    printf("\n");
  }

  printf("\n");
*/

return 0;
}
