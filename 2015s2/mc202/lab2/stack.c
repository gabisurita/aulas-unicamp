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
Node* NewNode(int Val){

  Node* New = (Node*)malloc(sizeof(Node));
  New->val = Val;
  New->next = NULL;

  return New;
}


/* Cria uma pilha */
Stack* NewStack(){

  Stack* St = malloc(sizeof(Stack));
  St->stp = NULL;
  return St;

}


/* Insere elemento na entrada da pilha */
void InStack(Stack** St, int val){  
  
  Stack* Iter = *St;
  
  Node* New = NewNode(val);  
 
  New->next = Iter->stp;
  Iter->stp = New;
  
}


/* Insere elemento na entrada da pilha */
void InOrderStack(Stack** St, int val){  
  
  Stack* Iter = *St;
  
  Node* NodeIter;
  Node* BackPointer = NULL;
  
  Node* New = NewNode(val);  
  
  NodeIter = Iter->stp;
  
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
    Iter->stp = New;
  }
  
  New->next = NodeIter;
 
    
}


/* Retira elemento da saida da pilha */
int OutStack(Stack** St){

  Node* OutNode;
  int OutValue;
  Stack* Iter = *St;

  OutNode = Iter->stp;

  if(OutNode){
    Iter->stp = OutNode->next;   
    OutValue = OutNode->val;
    free(OutNode);
    return OutValue;  
  }
  
  else{
    printf("\nException: Invalid OutStack() Request\n");
    exit(1);
  }
}


/* Verifica se a pilha possui elementos */
int NotNullStack(Stack** St){
  return (*St)->stp != NULL;
}


/* Libera pilha da memoria. */
void DestroyStack(Stack** St){
  
  while(NotNullStack(St)){
    OutStack(St);
  }
  
  free(*St);
}


