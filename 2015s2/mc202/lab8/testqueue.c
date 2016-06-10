#include <stdio.h>
#include "queue.h"

int main(){


  Queue Q = newQueue();
  inQueue(Q, 1);
  inQueue(Q, 2);
  inQueue(Q, 100);

  printf("%d\n", outQueue(Q));  
  printf("%d\n", outQueue(Q));  
  printf("%d\n", outQueue(Q));  
 
  printf("%d\n", outQueue(Q));  
  
  return 0;

}
