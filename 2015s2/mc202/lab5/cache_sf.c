/* Programa: cache_sf.c
 * Autor: Rodrigo Surita (RA: 139095)
 *
 * Descrição: Versão em arquivo único do programa cache.c
 * contendo:
 *  1. heap.h
 *  2. cache.c
 *  3. heap.c
 */

#include <stdio.h>
#include <stdlib.h>



/* Interface: heap.h
 * Autor: Rodrigo Surita (RA: 139095)
 *
 * Descrição: interface para um tipo abstrato de dados de
 * fila de prioridade.
 */

/* Define o tipo de dados do Heap */
typedef struct heapType {

  /* Dados */
  int val;

  /* Indice de prioridade */
  int prior;

} HeapType;

/* Tipo HEAP */
typedef struct heap {

  HeapType* data;
  int size;
  int count;

} Heap;

/* Cria um Heap de tamanho arbitrário */
Heap* newHeap(int size);

/* Insere elemento na Heap com prioridade k */
void pushHeap(Heap* Hp, HeapType data);

/* Remove elemento de maior prioridade na Heap */
HeapType popHeap(Heap* Hp);

/* Destrói a Heap */
void destroyHeap(Heap* Hp);



/* Programa: cache.c
 * Autor: Rodrigo Surita (RA: 139095)
 *
 * Descrição: Otimiza as remoções em cache de tamanho arbitrário a partir da
 * lista de ocorrências de elementos.
 *
 */

//#include <stdio.h>
//#include <stdlib.h>
//#include "heap.h"

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



/* Programa: heap.c
 * Autor: Rodrigo Surita (RA: 139095)
 *
 * Descrição: Tipo abstrato de dados fila de prioridade
 * descrita com uma estrutura abstrata de heap na
 * implementada na forma de vetor de vetor.
 */

//#include <stdio.h>
//#include <stdlib.h>
//#include "heap.h"

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
