#include <stdio.h>
#include <stdlib.h>

#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define MIN(x, y) (((x) < (y)) ? (x) : (y))

int AlgoProgDyn(int S, int k , int* V , int** M){
/*
  printf("--------------------------------------- \n");
  printf("APPEL S K\n");
  printf("S= %d \n",S);
  printf("k= %d \n",k);
  printf("\n");
  printf("--------------------------------------- \n");
  printf("\n");
*/

//  printf("A \n");
  if (S<0){
    return 1000000;
  }
  if (k==0){
//      printf("INTERIEUR A \n");
      M[S-1][k-1] = 1000000;
//      printf("Je retourne 1000000\n");
//      printf("\n");
      return 1000000;
  }
//  printf("B \n");
  if (S==0) {
//      printf("INTERIEUR B\n");
        M[S][k-1]=0;
//      printf("Je retourne 0\n");
//      printf("\n");
	    return 0;
  }
//  printf("C \n");

  /*printf("[S-1]=%d \n", S-1);
  printf("[k-1] =%d \n", k-1);
  printf("M[S-1][k-1]=%d \n", M[S-1][k-1]);
  */
  if (M[S-1][k-1]!= -1) {
/*     printf("INTERIEUR C \n");
     printf("Je retourne M[S][K]\n");
     printf("\n");
*/     return M[S-1][k-1];
  }
  else {
//  printf("Calcul x pour S= %d , k= %d \n",S,k);
	int x = AlgoProgDyn(S,k-1,V,M);
/*  printf("x = %d \n",x);
  printf("\n");

  printf("Calcul y pour S= %d , k= %d \n",S,k);
*/	int y = AlgoProgDyn(S-V[k-1],k,V,M) + 1;
/*  printf("y= %d \n",y);
  printf("\n");

  printf("--------------------------------------- \n");
  printf("MIN(x,y) = %d",MIN(x,y));
  printf("\n");
  printf("--------------------------------------- \n");
*/	M[S-1][k-1] = MIN(x,y);

/*  printf("\n");
  printf("--------------------------------------- \n");
  printf("FIN APPEL pour S= %d , k= %d \n",S,k);
  printf("\n");
  printf("--------------------------------------- \n");
*/
  return M[S-1][k-1];
  }
}
