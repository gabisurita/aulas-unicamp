

#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

int main(void){
  
  int n = 100;

  Heap* Hp = newHeap(n);
  
  for(int i=0; i<n; i++){
    HeapType New;
     
    New.val = i;
    New.prior = n-i;

    pushHeap(Hp, New);

    if(i % 10 == 0){
      HeapType Out = popHeap(Hp);

      printf("%d\n", Out.val);
    }
  }

  //printHeap(Hp,0);

  for(int i=0; i<100; i++){
    HeapType Out = popHeap(Hp);

    printf("%d\n", Out.val);
  }
  
  destroyHeap(Hp);
  return 0;
}
