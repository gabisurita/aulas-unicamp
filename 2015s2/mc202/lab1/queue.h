/********************************************************************
Programa: queue.h
Autor: Rodrigo Surita (RA:139095)

Descricao: Define um tipo abstrado de dados fila utilizando listas
ligadas circulares.
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
} Queue;



/* Malloc com verificacao */
void* Smalloc(int Size);

/* Cria uma fila */
Queue* NewQueue();
  
/* Insere elemento na entrada da fila */
void InQueue(Queue** Qe, int val);

/* Retira elemento da saida da fila */
int OutQueue(Queue** Queue);

/* Verifica se a lista possui elementos */
int NotNullQueue(Queue** Qe);

/* Libera fila da memoria. */
void DestroyQueue(Queue** Qe);

/* Cria um tipo no com valor arbitrario */
Node* NewNode(int Val);

/* Anexa um no apos outro */
void AppendNodeAfter(Node** Point, Node** New);

/* Anexa um no inicio de uma lista */
void AppendNodeStart(Node** Root, Node** New);

/* Libera (no a no) uma lista da memoria. */
void DestroyList(Node** Root);

