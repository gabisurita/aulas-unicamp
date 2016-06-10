#include <stdio.h>
#include <stdlib.h>
#include "oriented_graph.h"


int main(){

  int n = 5;

  Graph G = newGraph(n);
  
  for(int i=0; i<n; i++){
  
    int* data = (int*)malloc(sizeof(int));
    *data = i;
    setGraphVertex(G, i, (struct nodeData*)data); 
    
    //for(int j=1; j==1; j++) 
    if(i < 4)
      setEdgeGraph(G, i, i+1, 10);
  }

  
  for(int i=0; i<n; i++){
    printf("%d\n", hasPathGraph(G,i,4));
  }

  destroyGraph(G); 
  
  return 0;

}
