/********************************************************************
Programa: queue.h
Autor: Rodrigo Surita (RA:139095)

Descricao: Define um tipo abstrado de dados fila indexada utilizando 
listas ligadas circulares.
********************************************************************/

/* Define um tipo no com valor inteiro. */
typedef struct node {
  
  int val;
  struct node* next;

} Node;

/* Define um tipo fila */
typedef struct queue {

  Node* start;
  Node* end;
  int size;

} Queue;

/* Malloc com verificacao */
void* Smalloc(int mem);

/* Cria uma fila */
Queue* NewQueue();
  
/* Insere elemento na entrada da fila */
void InQueue(Queue* Qe, int val);

/* Retira elemento da saida da fila */
int OutQueue(Queue* Qe);

/* Retira elemento da entrada da fila (como pilha) */
int OutEndQueue(Queue* Qe);

/* Verifica se a lista possui elementos */
int NotNullQueue(Queue* Qe);

/* Retorna o número de elementos na fila */
int GetSizeQueue(Queue* Qe);

/* Devolve uma fila como um array */
int* AsArrayQueue(Queue* Qe);

/* Libera fila da memoria. */
void DestroyQueue(Queue* Qe);

/* Cria um tipo no com valor arbitrario */
Node* NewNode(int Val);

