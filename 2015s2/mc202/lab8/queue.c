/********************************************************************
Programa: queue.c
Autor: Rodrigo Surita (RA:139095)

Descricao: Implementa um tipo abstrado de dados fila utilizando 
listas ligadas circulares.

********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "mc202.h"

/* Cria um tipo no com valor arbitrario */
QueueNode* newNode(char* data){

  QueueNode* New = (QueueNode*)malloc(sizeof(QueueNode));
  
  if(!New)
    raiseMemoryError();
  
  New->data = data;

  return New;
}

/* Cria uma fila */
Queue newQueue(){

  Queue Qe = (Queue)malloc(sizeof(struct queue));
  
  if(!Qe)
    raiseMemoryError();
  
  Qe->start = NULL;
  Qe->end = NULL;
  Qe->size = 0;

  return Qe;
}

/* Insere elemento na entrada da fila */
void inQueue(Queue Qe, char* data){  
  
  QueueNode* New = newNode(data);  
  
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
char* outQueue(Queue Qe){

  QueueNode* OutNode;
  
  char* OutData;
  
  if(Qe->size <= 0){
    printf("Code Error: Invalid OutQueue call!\n");
    exit(1);
  }

  OutNode = Qe->start;

  if(Qe->end != Qe->start){
    Qe->start = Qe->start->next;    
  }
  else{
    Qe->start = NULL;
    Qe->end = NULL;
  }
  
  OutData = OutNode->data;
  
  Qe->size--;  
  free(OutNode);
  
  return OutData;  
}

/* Busca se há um elemento na fila */
char* searchQueue(Queue Qe, char* data, int (*Compare)(char*, char*)){

  QueueNode* Iter = Qe->start;

  for(int i=0; i<Qe->size; i++){
     
    if(Compare(Iter->data, data))
      return Iter->data;

    Iter = Iter->next;
  }
  
  return NULL;
}

/* Verifica se a lista possui elementos */
int notNullQueue(Queue Qe){
  return Qe->size > 0;
}

/* Retorna o número de elementos na fila */
int getSizeQueue(Queue Qe){  
  return Qe->size;
}

/* Itera os elementos de uma lista */
QueueNode* iterQueue(Queue Qe, QueueNode* Iter){
  
  if(Iter == NULL)
    return Qe->start;
  
  if(Iter == Qe->start)
    return NULL;

  return Iter->next;
}

/* Devolve uma fila como um array */
char** asArrayQueue(Queue Qe){
 
  QueueNode* Iter; 

  int n = Qe->size;
   
  char** Arr = NULL;
  
  if(n > 0){
    Iter =  Qe->start;
    Arr = (char**)malloc(n*sizeof(char*));
    
    if(!Arr)
      raiseMemoryError();

    for(int i=0; i<n; i++){
      Arr[i] = Iter->data;
      Iter = Iter->next;
    }
  }

  return Arr;
}

/* Libera fila da memoria. */
void destroyQueue(Queue Qe){
  
  while(notNullQueue(Qe)){
    
    char* Out = outQueue(Qe);
  
    free(Out);
  }
  
  free(Qe);
}

