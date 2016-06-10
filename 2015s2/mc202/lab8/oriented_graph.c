/* Programa: oriented_graph.c
 * Autor: Rodrigo Surita (RA 139095)
 *
 * Descrição:
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include "oriented_graph.h"
#include "mc202.h"
#include "minheap.h"

#define INF 0xFFFFFFFF

/* Cria um grafo de tamanho arbitrário */
Graph newGraph(int size){
  
  Graph G = (Graph)malloc(sizeof(struct graph));

  if(!G)
    raiseMemoryError();
  
  G->size = size;
  G->nodes = (GraphVertex*)malloc(size*sizeof(GraphVertex));
  G->edges = (int**)calloc(size*size, sizeof(int));

  if(!G->nodes || !G->edges)
    raiseMemoryError();

  for(int i=0; i<G->size; i++){
    G->nodes[i].data = NULL; 
  }

  return G;
}

/* Libera um grafo da memória */
void destroyGraph(Graph G){
  
  free(G->edges);
  free(G->nodes);
  free(G);
}

/* Adiciona uma aresta no grafo */
void setEdgeGraph(Graph G, int startId, int endId, int weight){
  
  if(startId < 0 || startId >= G->size){
    printf("Code Error: Invalid Egde start id\n");
    exit(1);
  }
  
  if(startId < 0 || startId >= G->size){
    printf("Code Error: Invalid Egde end id\n");
    exit(1);
  }
  
  G->edges[startId][endId] = weight;
}

/* Remove aresta no grafo */
void removeEdgeGraph(Graph G, int startId, int endId){

  G->edges[startId][endId] = 0;
}

/* Modifica o conteúdo de um vértice */
void setGraphVertex(Graph G, int id, struct nodeData* data){
  
  if(id < 0 || id >= G->size){
    printf("Code Error: Invalid setGraph id\n");
    exit(1);
  }

  G->nodes[id].data = data; 
}

/* Recupera o conteúdo de um vértice */
struct nodeData* getGraphVertex(Graph G, int id){
  
  return G->nodes[id].data;
}

int dijsktra(Graph G, int startId, int endId){
  
  
  int* Dists = (int*)malloc(G->size*sizeof(int)); 
  int* Lasts = (int*)malloc(G->size*sizeof(int));
  
  Heap Prior = newHeap(G->size);

  if(!Dists || !Lasts)
    raiseMemoryError();

  for(int i=0; i<G->size; i++){

    Dists[i] = INF;
    Lasts[i] = -1;  
  }

  Dists[startId] = 0;
  
  for(int i=0; i<G->size; i++)
    pushHeap(Prior, Dists[i], (char*)&i);
  
  while(Prior->count > 0){

    char* dataOut = popHeap(Prior).data;
    int i = (int)*dataOut;
      
      for(int j=0; j<G->size; i++){

        if(G->edges[i][j] &&
           (Dists[j] > Dists[i] + G->edges[i][j])){
          
           Dists[j] = Dists[i] + G->edges[i][j];
           Lasts[j] = i;
           
           pushHeap(Prior, Dists[i], (char*)&i);
        }
     }
  }

  int dist = Dists[endId];

  free(Dists);
  free(Lasts);
  
  destroyHeap(Prior);

  return dist;
}


