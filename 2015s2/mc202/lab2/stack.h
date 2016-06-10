/********************************************************************
Programa: stack.h
Autor: Rodrigo Surita (RA:139095)

Descricao: Define um tipo abstrado de dados pilha de inteiros 
utilizando lista ligada.
********************************************************************/

/* Define um tipo no com valor inteiro. */
typedef struct node {
  int val;
  struct node* next;
} Node;


/* Define um tipo pilha */
typedef struct stack {
  Node* stp;
} Stack;


/* Cria uma pilha */
Stack* NewStack();
  
/* Insere elemento nno topo da pilha */
void InStack(Stack** St, int val);

/* Insere elemento nno topo da pilha */
void InOrderStack(Stack** St, int val);

/* Retira elemento do topo da pilha */
int OutStack(Stack** St);

/* Verifica se a pilha possui elementos */
int NotNullStack(Stack** St);

/* Libera pilha da memoria. */
void DestroyStack(Stack** St);

/* Cria um tipo no com valor arbitrario */
Node* NewNode(int Val);
