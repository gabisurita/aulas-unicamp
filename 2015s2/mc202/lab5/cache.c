/* Programa: cache.c
 * Autor: Rodrigo Surita (RA: 139095)
 *
 * Descrição: Otimiza as remoções em cache de tamanho arbitrário a partir da
 * lista de ocorrências de elementos.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

/* Carrega entradas para o problema do Cache */
void parseInputs(int* c, int* n, int* a, int** SeqElements){

  scanf("%d", c);
  scanf("%d", n);
  scanf("%d", a);

  int* Seq = *SeqElements = (int*)malloc(*a*sizeof(int));

  if(!Seq){
    printf("Memory Error: Failed to malloc Inputs\n");
    exit(1);
  }

  for(int i=0; i<*a; i++)
    scanf("%d", &Seq[i]);
}

int main(){

  /* Entradas */
  int cacheSize;
  int nElements;
  int nAccess;
  int* AccessOrder;

  /* Saida: número de buscas fora do cache (cache miss) */
  int MissCount = 0;

  /* Le entradas */
  parseInputs(&cacheSize, &nElements, &nAccess, &AccessOrder);

  /* Heap para o proximo elemento a ser removido do cache */
  Heap* NextOut = newHeap(nAccess);

  /* Vetor que indica se um elemento está ou não no cache */
  int* InCache = (int*)malloc(nElements*sizeof(int));

  /* Vetor que armazena a última ocorrência de um elemento */
  int* LastEl = (int*)malloc(nAccess*sizeof(int));

  /* Vetor que armazena a próxima ocorrência de um elemento */
  int* NextEl = (int*)malloc(nAccess*sizeof(int));

  /* Número de espaços freeSpaces na cache  */
  int freeSpaces = cacheSize;

  /* Inicializa cache como vazio e ultimos acessos */
  for(int i=0; i<nElements; i++){
    LastEl[i] = nAccess;
    InCache[i] = 0;
  }

  /* Computa a diferença entre ocorrências de um elemento*/
  for(int i=nAccess-1; i>=0; i--){
    NextEl[i] = LastEl[AccessOrder[i]];
    LastEl[AccessOrder[i]] = i;
  }

  /* Insere ocorrencias na fila de prioridade */
  for(int i=0; i<nAccess; i++){

    int el = AccessOrder[i];

    /* Caso: elemento fora do cache (miss) */
    if(InCache[el] == 0){

      MissCount++;

      /* Caso: cache com espaços vazios */
      if(freeSpaces > 0){
        freeSpaces--;
      }

      /* Caso: cache cheio */
      else{
        /* Remove do cache a primeira ocorrencia da Heap */
        HeapType Out = popHeap(NextOut);
        InCache[AccessOrder[Out.val]] = 0;
      }
    }

    /* Insere ocorréncia na Heap */
    HeapType New;
    New.val = i;
    New.prior = NextEl[i];

    pushHeap(NextOut, New);

    /* Insere elemento no cache */
    InCache[el] = 1;
  }

  /* Libera memória */
  destroyHeap(NextOut);
  free(LastEl);
  free(NextEl);
  free(InCache);
  free(AccessOrder);

  /* Imprime a saída */
  printf("%d\n", MissCount);

  return 0;
}

