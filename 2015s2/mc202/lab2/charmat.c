/*******************************************************************
Programa: charmat.c
Autor: Rodrigo Surita (RA:139095)

Descricao: Define um tipo de dados de matriz de caracteres 
dinamicamente alocada.
*******************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "charmat.h"


/* Cria uma nova matriz de caracteres na memória. */
void NewCharMat(CharMat** Mat, int lines, int cols){
  
  int i;
  
  *Mat = (CharMat*)malloc(sizeof(CharMat));
  (*Mat)->el = (char**)malloc(lines*sizeof(char*));
  
  for(i=0; i<lines; i++)
    (*Mat)->el[i] = (char*)malloc(cols*sizeof(char));

  (*Mat)->lines = lines;
  (*Mat)->cols = cols;
}


/* Cria uma cópia de matriz de caracteres */
void CopyCharMat(CharMat** Ref, CharMat** Copy){
  
  CharMat* Iter = *Ref;
  
  NewCharMat(Copy, Iter->lines, Iter->cols);
  
  CharMat* Writer = *Copy;
  
  int i, j;
  
  for(i=0; i < Iter->lines; i++){
    for(j=0; j < Iter->cols; j++){
      Writer->el[i][j] = Iter->el[i][j];
    }
  }
}


/* Libera uma matriz de caracteres da memória */
void DestroyCharMat(CharMat** Mat){

  CharMat* Iter = *Mat;
  int i;
  
  for(i=0; i<Iter->lines; i++){
    free(Iter->el[i]);
  }
  
  free(Iter->el);
  free(Iter);
}


/* Imprime uma matriz de caracteres */
void PrintCharMat(CharMat** Mat){
  
  char** Els = (*Mat)->el;
  int lines = (*Mat)->lines;
  int cols = (*Mat)->cols;
  int i, j;
  
  for(i=0; i < lines; i++){
    for(j=0; j < cols; j++){
      printf("%c", (Els[i][j]));
    }
    printf("\n");
  }
}

