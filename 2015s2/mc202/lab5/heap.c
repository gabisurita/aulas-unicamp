/* Programa: heap.c
 * Autor: Rodrigo Surita (RA: 139095)
 *
 * Descrição: Tipo abstrato de dados fila de prioridade
 * descrita com uma estrutura abstrata de heap na
 * implementada na forma de vetor de vetor.
 */

#include <stdio.h>
#include <stdlib.h>

#include "heap.h"

/* Abstração do vetor para uma árvore */
#define lef(x) 2*x+1
#define rig(x) 2*x+2
#define par(x) (x-1)/2

/* Restabelece a propriedade de Heap de uma subárvore */
void heapify(Heap* Hp, int idx);

/* Cria um Heap vazio de tamanho arbitrário */
Heap* newHeap(int size){

  Heap* New = (Heap*)malloc(sizeof(Heap));

  if(!New){
    printf("Memory error: Failed to malloc Heap\n");
    exit(1);
  }

  New->size = size;
  New->count = 0;
  New->data = (HeapType*)malloc(size*sizeof(HeapType));

  if(!New->data){
    printf("Memory error: Failed to malloc Heap->data\n");
    exit(1);
  }

  return New;
}

/* Insere elemento na Heap com prioridade k */
void pushHeap(Heap* Hp, HeapType data){

  int count = Hp->count;

  if(count == Hp->size){
    printf("Code Error: Invalid push on full Heap\n");
  }

  /* Insere o elemento na última posição */
  Hp->data[count] = data;
  Hp->count++;

  /* Sobe o elemento na árvore */
  for(int idx=count; idx>0; idx=par(idx)){
    HeapType El = Hp->data[idx];
    HeapType Parent = Hp->data[par(idx)];

    if(El.prior > Parent.prior){
      HeapType Swap = Hp->data[idx];
      Hp->data[idx] = Hp->data[par(idx)];
      Hp->data[par(idx)] = Swap;
    }
    else{
      break;
    }
  }
}

/* Retorna o elemento de maior prioridade na Heap */
HeapType popHeap(Heap* Hp){

  if(!Hp->count){
    printf("Code Error: Invalid Pop request on empty Heap\n");
    exit(1);
  }

  HeapType Out;

  /* Troca topo pela folha de maior nível mais à direita */
  Hp->count--;
  Out = Hp->data[0];
  Hp->data[0] = Hp->data[Hp->count];

  /* Corrige a árvore */
  heapify(Hp, 0);

  return Out;
}

/* Destrói a Heap */
void destroyHeap(Heap* Hp){

  free(Hp->data);
  free(Hp);
}

/* Restabelece a propriedade de Heap de uma subárvore */
void heapify(Heap* Hp, int idx){

  HeapType* Data = Hp->data;

  int maxIndex = idx;

  if(lef(idx) < Hp->count &&
      Data[lef(idx)].prior > Data[maxIndex].prior)
    maxIndex = lef(idx);

  if(rig(idx) < Hp->count &&
      Data[rig(idx)].prior > Data[maxIndex].prior)
    maxIndex = rig(idx);

  /* Verifica se o maior indice não é o do pai */
  if(maxIndex != idx){

    /* Troca elemento */
    HeapType Swap;

    Swap = Data[maxIndex];
    Data[maxIndex] = Data[idx];
    Data[idx] = Swap;

    /* Verifica propriedade para a subárvore menor */
    heapify(Hp, maxIndex);
  }
}
