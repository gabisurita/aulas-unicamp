/********************************************************************
Programa: queue.c
Autor: Rodrigo Surita (RA:139095)

Descricao: Implementa um tipo abstrado de dados fila utilizando 
listas ligadas circulares.

********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

/* Malloc com verificacao */
void* Smalloc(int mem){
  
  void* Block = malloc(mem);
  if(Block == NULL){
    printf("Malloc Error\n");
    exit(1);
  }
  
  return Block;
}

/* Cria um tipo no com valor arbitrario */
Node* NewNode(int val){

  Node* New = (Node*)Smalloc(sizeof(Node));
  New->val = val;

  return New;
}

/* Cria uma fila */
Queue* NewQueue(){

  Queue* Qe = (Queue*)Smalloc(sizeof(Queue));
  Qe->start = NULL;
  Qe->end = NULL;
  Qe->size = 0;

  return Qe;
}

/* Insere elemento na entrada da fila */
void InQueue(Queue* Qe, int val){  
  
  Node* New = NewNode(val);  
  
  if(Qe->end){
    New->next = Qe->start;
    Qe->end->next = New;
    Qe->end = New;
  }
  else{
    Qe->start = New;
    Qe->end = New;
    Qe->end->next = New;
  }
  
  Qe->size++;
}

/* Retira elemento da saida da fila */
int OutQueue(Queue* Qe){

  Node* OutNode;
  int OutValue;
  
  if(Qe->size <= 0){
    printf("Invalid OutQueue call!");
    exit(100);
  }

  OutNode = Qe->start;

  if(Qe->end != Qe->start){
    Qe->start = Qe->start->next;    
  }
  else{
    Qe->start = NULL;
    Qe->end = NULL;
  }
  
  OutValue = OutNode->val;
  
  Qe->size--;  
  free(OutNode);
  
  return OutValue;  
}

/* Retira elemento da entrada da fila (como pilha) */
int OutEndQueue(Queue* Qe){

  Node* OutNode;
  int OutValue;

  OutNode = Qe->end;

  if(Qe->size <= 0){
    printf("Invalid OutQueue call!");
    exit(100);
  }

  if(Qe->end != Qe->start){
    Qe->start->next = Qe->end->next;    
  }
  else{
    Qe->start = NULL;
    Qe->end = NULL;
  }
  
  OutValue = OutNode->val;
  
  Qe->size--;  
  free(OutNode);
  
  return OutValue;  
}

/* Verifica se a lista possui elementos */
int NotNullQueue(Queue* Qe){
  return Qe->size > 0;
}

/* Retorna o número de elementos na fila */
int GetSizeQueue(Queue* Qe){  
  return Qe->size;
}

/* Devolve uma fila como um array */
int* AsArrayQueue(Queue* Qe){
 
  Node* Iter; 

  int n = Qe->size;
   
  int* Arr = NULL;
  
  if(n > 0){
    Iter =  Qe->start;
    Arr = (int*)Smalloc(n*sizeof(int));
    
    for(int i=0; i<n; i++){
      Arr[i] = Iter->val;
      Iter = Iter->next;
    }
  }

  return Arr;
}

/* Libera fila da memoria. */
void DestroyQueue(Queue* Qe){
  
  while(NotNullQueue(Qe)){
    OutQueue(Qe);
  }
  
  free(Qe);
}

