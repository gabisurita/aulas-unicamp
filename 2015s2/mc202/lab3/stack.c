/*******************************************************************
Programa: stack.c
Autor: Rodrigo Surita (RA:139095)

Descricao: Implementa um tipo abstrado de dados pilha de inteiros 
utilizando listas ligadas.
*******************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"


/* Cria um tipo no com valor arbitrario */
Node* NewNode(int val){

  Node* New = (Node*)malloc(sizeof(Node));
  New->val = val;
  New->next = NULL;

  return New;
}


/* Cria uma pilha */
Stack* NewStack(){

  Stack* St = malloc(sizeof(Stack));
  St->stp = NULL;
  St->size = 0;
  return St;
}


/* Insere elemento na entrada da pilha */
void InStack(Stack* St, int val){  
  
  Node* New = NewNode(val);  
 
  New->next = St->stp;
  St->stp = New;
  St->size++;  
}


/* Insere elemento na entrada da pilha */
void InOrderStack(Stack* St, int val){  
  
  Node* NodeIter;
  Node* BackPointer = NULL;
  
  Node* New = NewNode(val);  
  
  NodeIter = St->stp;
  
  /* Encotra o primeiro elemento menor ou percorre toda a lista */
  while(NodeIter){
    if(NodeIter->val < val){
      BackPointer = NodeIter;
      NodeIter = NodeIter->next;
    }
    else break;
  }
  
  if(BackPointer){
    BackPointer->next = New;
  }
  else{
    St->stp = New;
  }
  
  New->next = NodeIter;
  St->size++; 
}


/* Retira elemento da saida da pilha */
int OutStack(Stack* St){

  Node* OutNode;
  int OutValue;

  OutNode = St->stp;

  if(OutNode){
    St->stp = OutNode->next;   
    OutValue = OutNode->val;
    free(OutNode);
    
    St->size--;
    
    return OutValue;  
  }
  
  else{
    printf("\nException: Invalid OutStack() Request\n");
    exit(1);
  }
}


/* Verifica se a pilha possui elementos */
int NotNullStack(Stack* St){
  return St->stp != NULL;
}


/* Libera pilha da memoria. */
void DestroyStack(Stack* St){
  
  while(NotNullStack(St)){
    OutStack(St);
  }
  
  free(St);
}


