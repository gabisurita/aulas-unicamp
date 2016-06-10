/* Programa: heap.c
 * Autor: Rodrigo Surita (RA: 139095)
 *
 * Descrição: Tipo abstrato de dados fila de prioridade
 * descrita com uma estrutura abstrata de heap na
 * implementada na forma de vetor de vetor.
 */

typedef struct heapType{
  
  int prior;
  char *data;

} HeapType;

typedef struct heap{
  
  int size;
  int count;
  HeapType* data;

} *Heap; 


/* Restabelece a propriedade de Heap de uma subárvore */
void heapify(Heap Hp, int idx);

/* Cria um Heap vazio de tamanho arbitrário */
Heap newHeap(int size);

/* Insere elemento na Heap com prioridade k */
void pushHeap(Heap Hp, int prior, char* data);

/* Retorna o elemento de maior prioridade na Heap */
HeapType popHeap(Heap Hp);

/* Destrói a Heap */
void destroyHeap(Heap Hp);
