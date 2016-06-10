/********************************************************************
Programa: array.c
Autor: Rodrigo Surita (RA:139095)

Descricao: Define algumas operaçoes com arrays de inteiros.
********************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include "array.h"

/* Retorna indice da primeira ocorrencia de menor valor num array */
int MinArrayId(int Arr[], int Size){

  int i;
  int Min = Arr[0];
  int MinId = 0;
  
  for(i=1; i<Size; i++){
    if(Arr[i] < Min){
      Min = Arr[i];
      MinId = i;
    }
    else if(Arr[i] == Min){
      if(i < MinId){        
        MinId = i;
      }
    }
  }
  
  return MinId;
}


/* Retorna o elemento de maior valor em um array */
int MaxArray(int Arr[], int Size){

  int i;
  int Max = Arr[0];
  
  for(i=1; i<Size; i++){
    if(Arr[i] > Max){
      Max = Arr[i];
    }
  }
  
  return Max;
}


/* Ordena um Array e usando o algoritimo BubbleSort, mantendo um
indice da posicao original dos elementos */
void BubbleSortIds(int** Ids, int Arr[], int nT){

  int i, j;
  int Aux;
  
  for(i=0; i<nT-1; i++) {            
    for(j=0; j<nT-i-1; j++) {     
      if(Arr[j]<Arr[j+1]) {
        
          Aux = Arr[j];
          Arr[j] = Arr[j+1];
          Arr[j+1] = Aux;
          
          Aux = (*Ids)[j];
          (*Ids)[j] = (*Ids)[j+1];
          (*Ids)[j+1] = Aux;
          
      }
    }
  }
}

