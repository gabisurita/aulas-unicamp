#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

#define MAX_ITER 500000

/* Define máximos de iterações para limitar o tempo de execução */
#define TOP_DOWN_MAX_ITERS 100
#define BOTTOM_UP_MAX_ITERS 1

void ParseInput(int* nqueens, int* size, int* verbose){
  scanf("%d %d", nqueens, size);
  scanf("%d", verbose);
}

typedef struct solution{

  char** mat;
 
  int valid;

  int size;
  int nQueens;
  int nPawns;
  
  int iters;

} Solution;

Solution* NewSolution(int n){

  Solution* Sol = (Solution*)Smalloc(sizeof(Solution));

  Sol->size = n;
  Sol->valid = 0;
  Sol->iters = 0;
  Sol->nQueens = 0;
  Sol->nPawns = 0;
  
  char** Mat = Sol->mat = (char**)Smalloc(n*sizeof(char*));
  
  for(int i=0; i<n; i++){
    Mat[i] = (char*)Smalloc(n*sizeof(char));
  
    for(int j=0; j<n; j++)
      Mat[i][j] = '.';
  }
  return Sol;
}

void CopySolution(Solution* Base, Solution* Copy){

  int n = Base->size;

  Copy->valid = Base->valid;
  Copy->iters = Base->iters;
  Copy->nQueens = Base->nQueens;
  Copy->nPawns = Base->nPawns;

  char** Mat = Copy->mat;
  char** BMat = Base->mat;

  for(int i=0; i<n; i++){  
    for(int j=0; j<n; j++)
      Mat[i][j] = BMat[i][j];
  }
}

void ClearSolution(Solution* Sol){

  Sol->iters = Sol->nQueens = Sol->nPawns = 0;
  
  char** Mat = Sol->mat;
  int n = Sol->size; 
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++)
      Mat[i][j] = '.';
  }
}

void DestroySolution(Solution* Sol){
 
  int n = Sol->size;

  for(int i=0; i<n; i++)
    free(Sol->mat[i]);
  
  free(Sol->mat);
  free(Sol);
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
  Sol->mat[lin][col] = 'r';
}

void UnsetQueen(Solution* Sol, int lin, int col){

  Sol->nQueens--;
  Sol->mat[lin][col] = '.';
}

int IsSafeQueen(Solution* Sol, int lin, int col){
  
  char** Mat = Sol->mat;
  int n = Sol->size;


  /* Checa o próprio elemento */
  if(Mat[lin][col] == 'r' || Mat[lin][col] == 'p')
    return 0;

  /* Checa se há uma rainha imediatamente acima */
  for(int i=lin-1; i>=0; i--){
    if(Mat[i][col] == 'r') 
      return 0;

    else if(Mat[i][col] == 'p')
      break;
  }

  /* Checa se há uma rainha imediatamente abaixo */
  for(int i=lin+1; i<n; i++){
    if(Mat[i][col] == 'r') 
      return 0;

    else if(Mat[i][col] == 'p')
      break;
  }

  /* Checa se há uma rainha imediatamente acima */
  for(int i=col-1; i>=0; i--){
    if(Mat[lin][i] == 'r') 
      return 0;

    else if(Mat[lin][i] == 'p')
      break;
  }
   
  /* Checa se há uma rainha imediatamente abaixo */
  for(int i=col+1; i<n; i++){
    if(Mat[lin][i] == 'r') 
      return 0;

    else if(Mat[lin][i] == 'p')
      break;
  }

  int dPup;
  int dPdo;
  int dAup;
  int dAdo;

  if(lin < col){
    dPup = lin;
    dPdo = n - col;
  } 
  else{ 
    dPup = col;
    dPdo = n - lin;
  } 
 
  /*TODO CHECK BOUNDS*/
  if(lin < col){
    dAup = lin;
    dAdo = n - col;
  } 
  else{ 
    dAup = col;
    dAdo = n - lin;
  } 

  /* Checa se há uma rainha acima na diagonal principal */
  for(int i=1; i<=dPup; i++){
    if(Mat[lin-i][col-i] == 'r') 
      return 0;

    else if(Mat[lin-i][col-i] == 'p')
      break;
  }

  /* Checa se há uma rainha abaixo na diagonal principal */
  for(int i=1; i<dPdo; i++){
    if(Mat[lin+i][col+i] == 'r') 
      return 0;

    else if(Mat[lin+i][col+i] == 'p')
      break;
  }

  /* Checa se há uma rainha acima na diagonal auxiliar */
  for(int i=1; lin+i < n && col-i >= 0; i++){
    if(Mat[lin+i][col-i] == 'r') 
      return 0;

    else if(Mat[lin+i][col-i] == 'p')
      break;
  }

  /* Checa se há uma rainha abaixo na diagonal auxiliar */ 
  for(int i=1; lin-i >= 0 && col+i < n; i++){
    if(Mat[lin-i][col+i] == 'r') 
      return 0;

    else if(Mat[lin-i][col+i] == 'p')
      break;
  }

  return 1;  
} 

void SolveQueens(Solution* Sol, int lin,  int nQ){

  int n = Sol->size; 

  if(Sol->nQueens == nQ){
    Sol->valid = 1;
    return;              
  }

  else if(lin == n || Sol->iters >= MAX_ITER)
    return;

  else{
    for(int i=0; i<n; i++){

      if(IsSafeQueen(Sol, lin, i)){
        SetQueen(Sol, lin, i);      
        
        SolveQueens(Sol, lin, nQ);

        if(Sol->valid)  
          return;              

        SolveQueens(Sol, lin+1, nQ);
        
        if(Sol->valid)  
          return;              
        else 
          UnsetQueen(Sol, lin, i); 
      }
    }
  }
}

void SetPawn(Solution* Sol, int lin, int col){
  
  Sol->nPawns++;
  Sol->mat[lin][col] = 'p';
}

void UnsetPawn(Solution* Sol, int lin, int col){
  
  Sol->nPawns--;
  /*Sol->iters++;*/
  Sol->mat[lin][col] = '.';

}

int IsSafeKnight(Solution* Sol, int lin, int col){
  
  char** Mat = Sol->mat;

  if(Mat[lin][col] == 'r' || Mat[lin][col] == 'p')
    return 0;

  return 1;  
} 

void SolvePawns(Solution* Sol, int lin, int col, int nQ, int nP){
  
  int n = Sol->size;

  if(!nP){
    Sol->iters = 0;      
    SolveQueens(Sol, 0, nQ);

    if(Sol->valid)  
      return;              
  }

  else{
    for(int i=lin; i<n; i++){
      for(int j=col; j<n; j++){

        SetPawn(Sol, i, j);
        
        SolvePawns(Sol, i, j+1, nQ, nP-1);
          
        if(Sol->valid)  
          return;                
        else
          UnsetPawn(Sol, i, j);
      }
    }
  }
}

void SolvePawnsTopDown(Solution* Sol, Solution* Try,
    int lin, int col, int nQ, int nP){
  
  int n = Sol->size;
  
  if(nP == 0){
    ClearSolution(Sol);
    SolveQueens(Sol, 0, nQ);
    
    if(Sol->valid)  
      return;              
  }

  for(int i=lin; i<n; i++){
    for(int j=col; j<n; j++){

      if(Sol->iters > TOP_DOWN_MAX_ITERS)
        return;
      
      if(!IsSafeKnight(Try, i, j)){
        
        UnsetPawn(Try, i, j);
      
        if(Sol->nPawns > nP){
          SolvePawnsTopDown(Sol, i, j, nQ, nP);
        }
        
        SolveQueens(Sol, 0, nQ);
        
        if(Sol->valid){ 
           
          SolvePawnsTopDown(Sol, 0, 0, nQ, nP-1);
        }
        else{ 
          SetPawn(Sol, i, j);
        }
      }
    }  
  }

  DestroySolution(Try);
}

void TopDownSolve(Solution* Sol, int nQueens){

  int n = Sol->size;

  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      SetPawn(Sol, i, j);
    }
  }

  SolvePawnsTopDown(Sol, 0, 0, n*n - nQueens, nQueens);
}

int main (){
  
  /* Entradas */
  int nQueens;
  int size;
  int verbose;
  

  /* Carrega entradas */
  ParseInput(&nQueens, &size, &verbose); 

  /* Cria um registro de Solução */
  Solution* Sol = NewSolution(size);

  int maxPawns = size*size - nQueens; 
  for(int i=0; i<maxPawns; i++){     
    
    SolvePawns(Sol, 0, 0, nQueens, i);
      
    if(Sol->valid)
      break; 
  }
 
  if(Sol->valid)
    printf("%d\n", Sol->nPawns);
  else
    printf("-1\n");

  if(verbose && Sol->valid)
    PrintCharMat(Sol->mat, size, size);

  DestroySolution(Sol);

  return 0;
}
