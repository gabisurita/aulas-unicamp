/********************************************************************
Programa: queue.h
Autor: Rodrigo Surita (RA:139095)

Descricao: Define um tipo abstrado de dados fila indexada utilizando 
listas ligadas circulares.
********************************************************************/

/* Define um tipo no com valor inteiro. */
typedef struct node {
  
  char* data;
  struct node* next;
  
} QueueNode;

/* Define um tipo fila */
typedef struct queue {

  QueueNode* start;
  QueueNode* end;
  
  int size;

} *Queue;

/* Cria uma fila */
Queue newQueue();
  
/* Insere elemento na entrada da fila */
void inQueue(Queue Qe, char* data);

/* Retira elemento da saida da fila */
char* outQueue(Queue Qe);

/* Busca se há um elemento na fila */
char* searchQueue(Queue Qe, char* data, int (*Compare)(char*, char*));

/* Verifica se a lista possui elementos */
int notNullQueue(Queue Qe);

/* Retorna o número de elementos na fila */
int getSizeQueue(Queue Qe);

/* Itera os elementos de uma lista */
QueueNode* iterQueue(Queue Qe, QueueNode* Iter); 

/* Devolve uma fila como um array */
char** asArrayQueue(Queue Qe);

/* Libera fila da memoria. */
void destroyQueue(Queue Qe);

