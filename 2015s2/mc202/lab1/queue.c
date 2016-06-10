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
void* Smalloc(int Size){
  
  void* Mem = malloc(Size);
  if(Mem == NULL){
    printf("Malloc Error\n");
    exit(1);
  }
  
  return Mem;
}


/* Cria um tipo no com valor arbitrario */
Node* NewNode(int Val){

  Node* New = (Node*)Smalloc(sizeof(Node));
  New->val = Val;

  return New;
}



/* Libera (no a no) uma lista da memoria. */
void DestroyList(Node** Root){

  Node* Next;
  Node* Iter = *Root;

  
  while(Iter != NULL){
    Next = Iter->next;
    free(Iter);
    Iter = Next;
  }
}


/* Cria umq fila */
Queue* NewQueue(){

  Queue* Qe = Smalloc(sizeof(Queue));
  Qe->start = NULL;
  Qe->end = NULL;
  return Qe;

}



/* Insere elemento na entrada da fila */
void InQueue(Queue** Qe, int val){  
  
  Queue* Iter = *Qe;
  
  Node* New = NewNode(val);  
  
  if(Iter->end){
    New->next = Iter->start;
    Iter->end->next = New;
    Iter->end = New;
  }
  else{
    Iter->start = New;
    Iter->end = New;
    Iter->end->next = New;
  }
}



/* Retira elemento da saida da fila */
int OutQueue(Queue** Qe){

  Node* OutNode;
  int OutValue;
  Queue* Iter = *Qe;

  OutNode = Iter->start;

  if(Iter->end != Iter->start){
    Iter->start = Iter->start->next;    
  }
  else{
    Iter->start = NULL;
    Iter->end = NULL;
  }
  
  OutValue = OutNode->val;
  
  free(OutNode);
  
  return OutValue;  
}


/* Verifica se a lista possui elementos */
int NotNullQueue(Queue** Qe){
  return (*Qe)->end != NULL;
}


/* Libera fila da memoria. */
void DestroyQueue(Queue** Qe){
  
  while(NotNullQueue(Qe)){
    OutQueue(Qe);
  }
  
  free(*Qe);
}

