*******************************************************************
Programa: walls.c
Autor: Rodrigo Surita (RA:139095)

Descrição: Dada uma planta de um apartamento especificada no formato
descrito em [1], realiza uma reforma para eliminar comodos que não 
são retangulares, extraindo:

1. Número de comodos antes da reforma.
2. Lista dos comodos em ordem crescente de tamanho.
3. Número de comodos depois da reforma.
4. Número de blocos de muro removidos durante a reforma.

[1] https://susy.ic.unicamp.br:9999/mc202gh/02/lab02.pdf
*******************************************************************/

#include <stdio.h>
#include <stdlib.h>

#include "charmat.h"
#include "stack.h"


/* Faz a leitura e alocação de memória das entradas */
void InputParse(int* m, int* n, CharMat** Mat);

/* Checa se elemento é uma ponta de muro, retornando um código 
relativo à qual posição a borda está. */
int IsWallEdge(CharMat** Ap, int lin, int col);

/* Elimina um bloco na matriz de planta */
void KillBlock(CharMat** Ap, int lin, int col, int* count);

/*Percorre a planta da casa procurando muros salientes. */
int KillEdges(CharMat** Ap);

/* Verifica se o bloco é uma borda de um comodo */
int IsRoomEdge(CharMat** Ap, int lin, int col);

/* Percorre recursivamente os blocos de um comodo registrando a 
distancia e marcando os blocos trilhados com ',' */
int Walk(CharMat** Ap, int i, int j, int* l);

/* Registra informações sobre os comodos de uma planta */
void SetRooms(CharMat** Ap, int* nRooms, Stack** RoomSizes);

/* "Template" de saída de dados */
void PrintOutput(int nRoomsBefore, Stack** RoomSizes, int nRoomsAfter, int deadBlocks);


int main() {
  
  int lines;
  int cols;
  
  CharMat* Ap;
  CharMat* ApCopy;
  
  int deadBlocks;
  int nRoomsBefore;
  int nRoomsAfter;
   
  Stack* RoomSizes = NewStack();
  
  /* Carrega entradas */
  InputParse(&lines, &cols, &Ap);
  
  /* Extrai informações da planta antes da reforma */
  CopyCharMat(&Ap, &ApCopy);
  SetRooms(&ApCopy, &nRoomsBefore, &RoomSizes);
  DestroyCharMat(&ApCopy);
  
  /* Executa a reforma */
  deadBlocks = KillEdges(&Ap);
  
  /* Extrai informações da planta depois da reforma */
  SetRooms(&Ap, &nRoomsAfter, NULL);
  
  /* Imprime as informações pedidas na ordem desejada */
  PrintOutput(nRoomsBefore, &RoomSizes, nRoomsAfter, deadBlocks);
  
  
  /* Libera a memória */
  DestroyCharMat(&Ap);
  DestroyStack(&RoomSizes);
  
  return 0;
}


/* Faz a leitura e alocação de memória das entradas */
void InputParse(int* m, int* n, CharMat** Mat){

  scanf("%d%d\n", m, n);
  
  NewCharMat(Mat, *m, *n);

  CharMat* Iter = *Mat;
  
  for(int i=0; i < *m; i++){
    for(int j=0; j < *n; j++){
      scanf("%c", &Iter->el[i][j]);
    }
    scanf("\n");
  }
}


/* Checa se elemento é uma ponta de muro, retornando um código 
relativo à qual posição a borda está.

  1* 2
  3  4

  * representa o elemento localizado em  (lin, col).
 
*/
int IsWallEdge(CharMat** Ap, int lin, int col){

  char** Mat = (*Ap)->el;
  
  int blocks = 0;
  int code = 0;

  
  if(Mat[lin][col] == '*'){
    blocks++;
    code = 1;
  }
  if(Mat[lin][col+1] == '*'){
    blocks++;
    code = 2;
  }
  if(Mat[lin+1][col] == '*'){
    blocks++;
    code = 3;
  }
  if(Mat[lin+1][col+1] == '*'){
    blocks++;
    code = 4;
  }
  
  return (blocks == 1) * code;

}


/* Elimina um bloco na matriz de planta */
void KillBlock(CharMat** Ap, int lin, int col, int* count){
  (*count)++;
  (*Ap)->el[lin][col] = '.';
}


/* Elimina recursivamente um muro saliente na matriz de planta 
destruindo os elementos de muro saliente adjacentes ao elemento 
testado. */
void KillWall(CharMat** Ap, int i, int j, int* c){
      
  int status = IsWallEdge(Ap, i, j);
  
  /* Se o elemento é um muro saliente */
  if(status > 0){
    /* Muro saliente no canto superior esquerdo */
    if(status == 1){
      KillBlock(Ap, i, j, c);
      KillWall(Ap, i-1, j-1, c);
      KillWall(Ap, i, j-1, c);
      KillWall(Ap, i-1, j, c);
    }
    /* Muro saliente no canto superior direito */
    if(status == 2){ 
      KillBlock(Ap, i, j+1, c);
      KillWall(Ap, i-1, j, c);
      KillWall(Ap, i-1, j+1, c);
      KillWall(Ap, i, j+1, c);
    }
    /* Muro saliente no canto inferior esquerdo */
    if(status == 3){
      KillBlock(Ap, i+1, j, c);
      KillWall(Ap, i, j-1, c);
      KillWall(Ap, i+1, j, c);
      KillWall(Ap, i+1, j-1, c);
    }
    /* Muro saliente no canto inferior direito */
    if(status == 4){
      KillBlock(Ap, i+1, j+1, c);
      KillWall(Ap, i, j+1, c);
      KillWall(Ap, i+1, j, c);
      KillWall(Ap, i+1, j+1, c);
    }
  }
}  


/*Percorre a planta da casa procurando muros salientes. */
int KillEdges(CharMat** Ap){
  
  int m = (*Ap)->lines;
  int n = (*Ap)->cols;
  
  int status;
  int count = 0; 
  
  for(int i=1; i<m-1; i++){
    for(int j=1; j<n-1; j++){
      
      status = IsWallEdge(Ap, i, j);
      
      if(status > 0){
        KillWall(Ap, i, j, &count);
      }
    }
  }

  return count;
}


/* Verifica se o bloco é uma borda de um comodo */
int IsRoomEdge(CharMat** Ap, int lin, int col){

  char** Mat = (*Ap)->el;
  
  if(Mat[lin][col] == '.'
  || Mat[lin][col+1] == '.'
  || Mat[lin+1][col] == '.'
  || Mat[lin+1][col+1] == '.')
    return 1;
  
  else
    return 0;
}  


/* Percorre recursivamente os blocos de um comodo registrando a 
distancia e marcando os blocos trilhados com ',' */
int Walk(CharMat** Ap, int i, int j, int* l){
  
  int m = (*Ap)->lines;
  int n = (*Ap)->cols;
  char** Mat = (*Ap)->el;
  
  if(i == 0|| i >= m || j == 0 || j >= n)
    return 0;
  
  if(Mat[i][j] == '.'){
    
    Mat[i][j] = ',';
    (*l)++;
    
    Walk(Ap, i, j+1,l);
    Walk(Ap, i+1, j,l);
    Walk(Ap, i, j-1,l);
    Walk(Ap, i-1, j,l);    
    
  }
  
  return *l;

}    


/* Registra informações sobre os comodos de uma planta */
void SetRooms(CharMat** Ap, int* nRooms, Stack** RoomSizes){

  int m = (*Ap)->lines;
  int n = (*Ap)->cols;
  int status;
  int roomSize;
  
  *nRooms = 0;
  
  for(int i=1; i<m-1; i++){
    for(int j=1; j<n-1; j++){
      
      status = IsRoomEdge(Ap, i, j);

      if(status > 0){
        
        roomSize = 0;
        
        Walk(Ap, i, j, &roomSize);

        if(roomSize > 0){
          (*nRooms)++;
          if(RoomSizes){
            InOrderStack(RoomSizes, roomSize);        
          }
        }
      }    
    }
  }
}


/* Template de impressão de dados */
void PrintOutput(int nRoomsBefore, Stack** RoomSizes, int nRoomsAfter, int deadBlocks){
  
  int i;
  
  printf("%d\n", nRoomsBefore);
  
  for(i=0; i<nRoomsBefore; i++){
    printf("%d", OutStack(RoomSizes));
    
    if(i+1<nRoomsBefore){
      printf(" ");
    }
  }
  
  printf("\n%d\n", nRoomsAfter);
  printf("%d\n", deadBlocks);  
}

