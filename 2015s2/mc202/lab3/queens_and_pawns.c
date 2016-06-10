#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

#define MAX_ITER 100

void ParseInput(int* nqueens, int* size, int* verbose){
  scanf("%d %d", nqueens, size);
  scanf("%d", verbose);
}

typedef struct solution{

  Queue** queens;
  Queue** knights;
  
  int size;
  int nQueens;
  int nKnights;
  
  int iters;

} Solution;

Solution* NewSolution(int n){

  Solution* Sol = (Solution*)Smalloc(sizeof(Solution));

  Sol->size = n;
  Sol->iters = Sol->nQueens = Sol->nKnights = 0;
  
  /* Inicializa filas de posições referentes a colunas */
  Sol->queens = (Queue**)Smalloc(n*sizeof(Queue*));
  Sol->knights = (Queue**)Smalloc(n*sizeof(Queue*));  
  
  int i; 
  
  /* Inicializa cada fila de coluna */
  for(i=0; i<n; i++){
    Sol->queens[i] = NewQueue();
    Sol->knights[i] = NewQueue();  
  } 

  return Sol;
}

void DestroySolution(Solution* Sol){
 
  int n = Sol->size;

  for(int i=0; i<n; i++){
    DestroyQueue(Sol->queens[i]);
    DestroyQueue(Sol->knights[i]);
  }
  
  free(Sol->queens);
  free(Sol->knights);

  free(Sol);
}

char** AsMatSolution(Solution* Sol){
  
  Queue* LineQueens;
  Queue* LineKnights;
  
  int* LineQueensPos;
  int* LineKnightsPos;

  int nLineQueens;
  int nLineKnights;

  int n = Sol->size;

  char** Mat = (char**)Smalloc(n*sizeof(char*));
   
  for(int i=0; i<n; i++){

    Mat[i] = (char*)Smalloc(n*sizeof(char));

    LineQueens = Sol->queens[i]; 
    LineKnights = Sol->knights[i];

    nLineQueens = GetSizeQueue(LineQueens);
    nLineKnights = GetSizeQueue(LineKnights);

    LineQueensPos = AsArrayQueue(LineQueens);
    LineKnightsPos = AsArrayQueue(LineKnights);
 
    for(int j=0; j<n; j++){
      Mat[i][j] = '.';    
    }

    if(LineQueens){
      for(int j=0; j<nLineQueens; j++){ 
        int col = LineQueensPos[j];
        Mat[i][col] = 'r';
      }
    }
    
    if(LineKnights){
      for(int j=0; j<nLineKnights; j++){ 
        int col = LineKnightsPos[j];
        Mat[i][col] = 'p';
      }
    }
    
    free(LineQueensPos);
    free(LineKnightsPos);
  }

  return Mat;
}

void PrintChessBoard(Solution* Sol){
  
  int n = Sol->size;

  int* Qpos;
  int* Kpos; 
  
  int jq = 0;
  int jk = 0;

  Queue* LineQueens;
  Queue* LineKnights;

  for(int i=0; i<n; i++){
    LineQueens = Sol->queens[i]; 
    LineKnights = Sol->knights[i];

    if(NotNullQueue(LineQueens)){
      Qpos = AsArrayQueue(LineQueens);
    }
    else{
      Qpos = NULL;
    }
      
    if(NotNullQueue(LineKnights)){
      Kpos = AsArrayQueue(LineKnights);
    }
    else{
      Kpos = NULL;
    }

    for(int j=0; j<n; j++){ 
      if(Qpos){
        if(j == Qpos[jq]){
          printf("Q");
          jq++;
          continue;
        }
      }
      if(Kpos){
        if(j == Kpos[jk]){
          printf("K");
          jk++;
          continue;
        }
      }
      printf(".");
    }
    printf("\n");
    
    jq = 0;
    jk = 0;
    free(Qpos);
    free(Kpos);
  }
}

void PrintCharMat(char** Mat, int m, int n){
  
  for(int i=0; i<m; i++){
    for(int j=0; j<n; j++){
      printf("%c", Mat[i][j]);
    }
    printf("\n");
  }
}

void DestroyCharMat(char** Mat, int m){

  for(int i=0; i<m; i++){
    free(Mat[i]);
  }

  free(Mat);
}

void SetQueen(Solution* Sol, int lin, int col){
  
  Sol->nQueens++;
  InQueue(Sol->queens[lin], col);
}

void UnsetQueen(Solution* Sol, int lin){
  
  Sol->nQueens--;
  Sol->iters++;
  OutEndQueue(Sol->queens[lin]);
}

int IsSafeQueen(Solution* Sol, int lin, int col){
  
  char** Mat = AsMatSolution(Sol);
  int n = Sol->size;

  if(Mat[lin][col] == 'r' || Mat[lin][col] == 'p'){
    DestroyCharMat(Mat, Sol->size);
    return 0;      
  }

  for(int i=0; i<n; i++){
    if(Mat[lin][i] == 'r' ||
       Mat[i][col] == 'r' ||
       Mat[(i+lin)%n][(i+col)%n] == 'r'){
      
      DestroyCharMat(Mat, Sol->size);
      return 0;      
    }
  }

  DestroyCharMat(Mat, Sol->size);
  return 1;  
} 

int SolveQueens(Solution* Sol, int lin,  int nReqQueens){

  int hasSol;
  int n = Sol->size;
  
  if(Sol->nQueens == nReqQueens)
    return 1;

  else if(lin >= n || Sol->iters >= MAX_ITER)
    return 0;

  else{
    for(int i=0; i<n; i++){
      
      if(IsSafeQueen(Sol, lin, i)){

        SetQueen(Sol, lin, i);      
        
        hasSol = SolveQueens(Sol, lin, nReqQueens); 
        if(hasSol)
          return 1;       
       

        hasSol = SolveQueens(Sol, lin+1, nReqQueens);
        if(hasSol)
          return 1;
        else 
          UnsetQueen(Sol, lin); 
      }
    }

    return 0;
  }
}

void SetKnight(Solution* Sol, int lin, int col){
  
  Sol->nKnights++;
  InQueue(Sol->knights[lin], col);
}

void UnsetKnight(Solution* Sol, int lin){
  
  Sol->nKnights--;
  Sol->iters++;
  OutEndQueue(Sol->knights[lin]);
}

int IsSafeKnight(Solution* Sol, int lin, int col){
  
  char** Mat = AsMatSolution(Sol);
  int n = Sol->size;

  if(Mat[lin][col] == 'r' || Mat[lin][col] == 'p'){
    DestroyCharMat(Mat, Sol->size);
    return 0;      
  }

  DestroyCharMat(Mat, Sol->size);
  return 1;  
} 

int SolveKnights(Solution* Sol, int lin,  int nReqKnights){

  int hasSol;
  int n = Sol->size;
  
  if(Sol->nQueens == nReqKnights)
    return 1;

  else if(lin >= n || Sol->iters >= MAX_ITER)
    return 0;

  else{
    for(int i=0; i<n; i++){
      
      if(IsSafeKnight(Sol, lin, i)){

        SetKnight(Sol, lin, i);      
        
        hasSol = SolveKnights(Sol, lin, nReqKnights); 
        if(hasSol)
          return 1;       
       

        hasSol = SolveKnights(Sol, lin+1, nReqKnights);
        if(hasSol)
          return 1;
        else 
          UnsetKnight(Sol, lin); 
      }
    }

    return 0;
  }
}

int main (){

  int nQueens;
  int size;
  int verbose;
  
  Solution* Sol;
  char** PrintMat;
  int hasSol;
  
  int start = 0;
  int limit;

  ParseInput(&nQueens, &size, &verbose);
  
  if(nQueens - size > 1){
    start = 1;
  }
  if(size > 15){
    start = size;
  } 

  for(int i=start; i<size; i++){
    for(int j=0; j<size; j++){
      Sol = NewSolution(size);
      hasSol = SolveQueens(Sol, 0, nQueens);

      start = (nQueens - size > 0);
    }
  }

  if(hasSol)
    printf("%d\n", Sol->nKnights);
  else
    printf("-1\n");

  if(verbose && hasSol){
    PrintMat = AsMatSolution(Sol);
    PrintCharMat(PrintMat, size, size);
    DestroyCharMat(PrintMat, size);
  }

  DestroySolution(Sol);

  return 0;
}


