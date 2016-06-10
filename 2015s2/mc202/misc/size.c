#include <stdio.h>
#include <stdlib.h>

int main(){

  int *p = malloc(4*sizeof(int));

  printf("%d\n%d\n", sizeof(int*), sizeof(*p));

  return 0;

}
