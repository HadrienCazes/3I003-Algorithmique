#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "readlib.h"
#include <math.h>

int **M;
int *V;

int AlgoProgDyn(int k, int s)
{
  if (s == -1) {
    return 0;
  }

  if (k == -1) {
    return 30000;
  }

  if (k < -1) {
    return 30000;
  }

  if (s < -1) {
    return 30000;
  }

  if (M[s][k] != -1) {
    return M[s][k];
  } else {
    int x = AlgoProgDyn(k-1, s);
    int y = AlgoProgDyn(k, s-V[k]) + 1;
    M[s][k] = fmin(x, y);
    return M[s][k];
  }
}


int main(int argc, char **argv)
{
  int s, k;

  FILE *fp = fopen(argv[1], "r");

  s = read_int(fp);
  skip_line(fp);
  k = read_int(fp);
  skip_line(fp);
  V = (int *) malloc(sizeof(int) * k);
  read_V(fp, V, k);

  int i, j;


  M = (int **) malloc(sizeof(int *) * s);

  for (i = 0; i < s; i++) {
    M[i] = (int*) malloc(sizeof(int) * k);
  }

  for (i = 0; i < s; i++) {
    for (j = 0; j < k; j++) {
      M[i][j] = -1;
    }
  }

  int k2 = k-1, s2 = s-1, r;

  r = AlgoProgDyn(k2, s2);
  printf("%d", r);


  /* for (i = 0; i < s; i++) { */
  /*   for (j = 0; j < k; j++) { */
  /*     printf("%d\t", M[i][j]); */
  /*   } */
  /*   printf("\n"); */
  /* } */

  for (i = 0; i < s; i++) {
    free(M[i]);
  }
  free(M);
  free(V);
  fclose(fp);
  return r;
}
