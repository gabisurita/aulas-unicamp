/***************************************************************************
* Programa: queens.c                                                       *
* Autor: Rodrigo Surita (RA:139095)                                        *
*                                                                          *
* Descrição: Resolve o problema das N rainhas e P peões [1] exaustivamen-  *
* te para testes pequenos por meio do algoritmo especificado em [2] e uti- *
* lizando a técnica de "BackTracking" para o subproblema das N rainhas.    *
*                                                                          *
* [1] https://susy.ic.unicamp.br:9999/mc202gh/03/lab03.pdf                 *
* [2] https://susy.ic.unicamp.br:9999/mc202gh/03/aux/pseudocodigo.pdf      *
*                                                                          *
***************************************************************************/


#include <stdio.h>
#include <stdlib.h>

/* Tipo registro de solução do problema especificado */
typedef struct solution{
  
  /* Matriz do tabluleiro */
  char** mat;
  
  /* Tamanho do tabuleiro */
  int size;
  
  /* Flag de validade da solução */
  int valid;
 
  /* Contadores de rainhas e peões da solução */
  int nQueens;
  int nPawns;
 
  /* Contadores de rainha por linha/coluna da solução */
  int* queensLin;
  int* queensCol;

} Solution;

/* Cria um registro de solução */
Solution* NewSolution(int n);

/* Destrói registro de solução */
void DestroySolution(Solution* Sol);

/* Malloc com verificação de válidade do endereço */
void* Smalloc(int mem);

/* Carrega entradas do problema */
void ParseInput(int* nqueens, int* size, int* verbose);

/* Procura se existe solução com nP peões */
void SolvePawns(Solution* Sol, int lin, int col, int nQ, int nP);

/* Procura se existe solução com nQ rainhas */
void SolveQueens(Solution* Sol, int lin,  int nQ);

/* Aloca rainha na posição especificada */
void SetQueen(Solution* Sol, int lin, int col);

/* Retira rainha da posição especificada */
void UnsetQueen(Solution* Sol, int lin, int col);

/* Verifica se a posição não é atacada por rainhas */
int IsSafeQueen(Solution* Sol, int lin, int col);

/* Aloca peão na posição especificada */
void SetPawn(Solution* Sol, int lin, int col);

/* Retira peão da posição especificada */
void UnsetPawn(Solution* Sol, int lin, int col);

/* Imprime matriz de caracteres */
void PrintCharMat(char** Mat, int m, int n);


int main (){
  
  /* Entradas */
  int nQueens;
  int size;
  int verbose;  

  /* Carrega entradas */
  ParseInput(&nQueens, &size, &verbose); 

  /* Cria um registro de Solução */
  Solution* Sol = NewSolution(size);
  
  /* Número máximo de peões (todas as casas preenchidas) */
  int maxPawns = size*size - nQueens; 
   
  for(int i=0; i<=maxPawns; i++){
    /* Procura se uma solução existe com i peões */
    SolvePawns(Sol, 0, 0, nQueens, i);
    
    if(Sol->valid)
      break; 
  }
 
  /* Imprime o número de peões ou -1 se não há solução */
  if(Sol->valid)
    printf("%d\n", Sol->nPawns);
  else
    printf("-1\n");

  /* Imprime a matriz da solução encontrada */
  if(verbose && Sol->valid)
    PrintCharMat(Sol->mat, size, size);

  DestroySolution(Sol);

  return 0;
}

/* Malloc com verificação de válidade do endereço */
void* Smalloc(int mem){
  
  void* Block = malloc(mem);
  if(Block == NULL){
    printf("Malloc Error\n");
    exit(1);
  }
  
  return Block;
}

/* Carrega entradas do problema */
void ParseInput(int* nqueens, int* size, int* verbose){
  scanf("%d %d", nqueens, size);
  scanf("%d", verbose);
}

/* Cria um registro de solução */
Solution* NewSolution(int n){

  Solution* Sol = (Solution*)Smalloc(sizeof(Solution));

  Sol->size = n;
  Sol->valid = 0;

  Sol->nQueens = 0;
  Sol->nPawns = 0;
 
  char** Mat = Sol->mat = (char**)Smalloc(n*sizeof(char*));
  
  Sol->queensCol = (int*)Smalloc(n*sizeof(int)); 
  Sol->queensLin = (int*)Smalloc(n*sizeof(int));
  
  for(int i=0; i<n; i++){

    Sol->queensCol[i] = 0;
    Sol->queensLin[i] = 0;
    
    Mat[i] = (char*)Smalloc(n*sizeof(char));
      
    for(int j=0; j<n; j++)
      Mat[i][j] = '.';
  }
  return Sol;
}

/* Destrói registro de solução */
void DestroySolution(Solution* Sol){
 
  int n = Sol->size;

  for(int i=0; i<n; i++)
    free(Sol->mat[i]);
  
  free(Sol->queensCol);
  free(Sol->queensLin); 
  free(Sol->mat);
  free(Sol);
}

/* Imprime matriz de caracteres */
void PrintCharMat(char** Mat, int m, int n){
  
  for(int i=0; i<m; i++){
    for(int j=0; j<n; j++){
      printf("%c", Mat[i][j]);
    }
    printf("\n");
  }
}

/* Aloca rainha na posição especificada */
void SetQueen(Solution* Sol, int lin, int col){
  
  Sol->nQueens++;
  Sol->mat[lin][col] = 'r';
  Sol->queensLin[lin]++;
  Sol->queensCol[col]++;
}

/* Retira rainha da posição especificada */
void UnsetQueen(Solution* Sol, int lin, int col){

  Sol->nQueens--;
  Sol->mat[lin][col] = '.';
  Sol->queensLin[lin]--;
  Sol->queensCol[col]--;
}

/* Verifica se a posição não é atacada por rainhas */
int IsSafeQueen(Solution* Sol, int lin, int col){
  
  char** Mat = Sol->mat;
  int n = Sol->size;
  
  int QnLin = Sol->queensLin[lin];
  int QnCol = Sol->queensCol[col];

  /* Checa o próprio elemento */
  if(Mat[lin][col] == 'r' || Mat[lin][col] == 'p')
    return 0;

  /* Checa se há mais rainhas na coluna */ 
  if(QnCol > 0){
    /* Checa se há uma rainha imediatamente acima */
    for(int i=lin-1; i>=0; i--){
      if(Mat[i][col] == 'r') 
        return 0;

      else if(Mat[i][col] == 'p')
        break;
    }

    /* Checa se há uma rainha imediatamente abaixo (desnecessário) */
    /*for(int i=lin+1; i<n; i++){*/
      /*if(Mat[i][col] == 'r') */
        /*return 0;*/

      /*else if(Mat[i][col] == 'p')*/
        /*break;*/
    /*}*/
  }
  
  /* Checa se há mais rainhas na linha */
  if(QnLin > 0){
    /* Checa se há uma rainha imediatamente a esquerda */
    for(int i=col-1; i>=0; i--){
      if(Mat[lin][i] == 'r') 
        return 0;

      else if(Mat[lin][i] == 'p')
        break;
    }
     
    /* Checa se há uma rainha imediatamente a direita */
    for(int i=col+1; i<n; i++){
      if(Mat[lin][i] == 'r') 
        return 0;

      else if(Mat[lin][i] == 'p')
        break;
    }
  }

  /* Checa se há uma rainha acima na diagonal principal */
  for(int i=1; lin-i>=0 && col-i>=0; i++){
    if(Mat[lin-i][col-i] == 'r') 
      return 0;

    else if(Mat[lin-i][col-i] == 'p')
      break;
  }

  /* Checa se há uma rainha abaixo na diagonal principal */
  /*for(int i=1; lin+i<n && col+i<n; i++){*/
    /*if(Mat[lin+i][col+i] == 'r') */
      /*return 0;*/

    /*else if(Mat[lin+i][col+i] == 'p')*/
      /*break;*/
  /*}*/

  /* Checa se há uma rainha acima na diagonal auxiliar */
  for(int i=1; lin-i >= 0 && col+i < n; i++){
    if(Mat[lin-i][col+i] == 'r') 
      return 0;

    else if(Mat[lin-i][col+i] == 'p')
      break;
  }

  /* Checa se há uma rainha abaixo na diagonal auxiliar */ 
  /*for(int i=1; lin+i < n && col-i >= 0; i++){*/
    /*if(Mat[lin+i][col-i] == 'r') */
      /*return 0;*/

    /*else if(Mat[lin+i][col-i] == 'p')*/
      /*break;*/
  /*}*/

  return 1;  
} 

/* Procura se existe solução com nQ rainhas */
void SolveQueens(Solution* Sol, int lin,  int nQ){

  int n = Sol->size;   

  /* Se a solução possuí nQ rainhas possíveis ela é válida*/
  if(Sol->nQueens == nQ){
    Sol->valid = 1;
    return;              
  }
  /* Se as linhas foram esgotadas a solução não é possível */
  else if(lin >= n)
    return;

  else{
    /* Tenta alocar rainhas na linha */
    for(int i=0; i<n; i++){
      /* Se a solução é possível */
      if(IsSafeQueen(Sol, lin, i)){

        SetQueen(Sol, lin, i);

        /* Tenta solução com mais rainhas na mesma linha */
        for(int j=0; j<n; j++){
          SolveQueens(Sol, lin+j, nQ);

          if(Sol->valid)  
            return;              
        }  
        
        UnsetQueen(Sol, lin, i); 
      }
    }
  }
}

/* Aloca peão na posição especificada */
void SetPawn(Solution* Sol, int lin, int col){
  
  Sol->nPawns++;
  Sol->mat[lin][col] = 'p';
}

/* Retira peão da posição especificada */
void UnsetPawn(Solution* Sol, int lin, int col){
  
  Sol->nPawns--;
  Sol->mat[lin][col] = '.';

}

/* Procura se existe solução com nP peões */
void SolvePawns(Solution* Sol, int lin, int col, int nQ, int nP){
  
  int n = Sol->size;
   
  /* Se não há peões para serem alocados */
  if(!nP){

    /* Tenta alocar rainhas */
    SolveQueens(Sol, 0, nQ);
    
    /* Verifica se existe solução */
    if(Sol->valid)  
      return;              
  }
 
  else{
    for(int j=col; j<n; j++){
      /* Aloca peão em todas as posições */ 
      SetPawn(Sol, lin, j);       
      
      /* Tenta alocar mais peões */
      SolvePawns(Sol, lin, j+1, nQ, nP-1);
      
      /* Verifica se existe solução */
      if(Sol->valid)  
        return;

      /* Descasta soluções inválidas */        
      else
        UnsetPawn(Sol, lin, j);
    }

    for(int i=lin+1; i<n; i++){
      for(int j=0; j<n; j++){
        /* Aloca peão em todas as posições */ 
        SetPawn(Sol, i, j);       
        
        /* Tenta alocar mais peões */
        SolvePawns(Sol, i, j+1, nQ, nP-1);
        
        /* Verifica se existe solução */
        if(Sol->valid)  
          return;

        /* Descasta soluções inválidas */        
        else
          UnsetPawn(Sol, i, j);
      }
    }
  }
}
