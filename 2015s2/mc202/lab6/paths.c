/* Programa: paths.c
 * Autor: Rodrigo de Castro Surita (RA:139095)
 * 
 * Descrição: Soluciona o problema de caminhos descrito em [1] que estima
 * se é possível a partir da origem chegar até o útimo elemento de um
 * vetor com os caminhos:
 *
 * A{k+1] = A[k] + v[x]
 * A[k+1] = A[k] - V[x]
 * 
 * Rebendo como entradas o número de elementos do vetor e seus elementos
 * em ordem sequencial.
 *
 * [1] http://susy.ic.unicamp.br:9999/mc202gh/06/lab06.pdf
 *
 */

#include <stdio.h>
#include <stdlib.h>

/* Estrutura com parâmetros combinatórios para a busca da solução */
struct solution{
  
  int nPaths;
  int* paths;
  int* usedPaths;
  int current;
};

/* Função que carrega as entradas do problema */
void parseInputs(int* n, int** Arr);

/* Função que busca solução do problema */
int solve(struct solution Sol);

int main(){
  
  struct solution Sol;
 
  /* Carrega entradas */
  parseInputs(&Sol.nPaths, &Sol.paths); 
  
  /* Coloca a busca na posição inicial */
  Sol.usedPaths = (int*)calloc(Sol.nPaths, sizeof(int)); 
  Sol.current = 0;
  
  if(!Sol.usedPaths){
    printf("Failed to malloc Array\n");
    exit(1);
  }
  
  /* Verifica se existe solução */
  if(solve(Sol))
    printf("sim\n");
  else
    printf("nao\n");
  
  /* Libera memória */
  free(Sol.paths);
  free(Sol.usedPaths);
  return 0;
}

/* Função que carrega as entradas do problema */
void parseInputs(int* n, int** Arr){
  
  scanf("%d", n);

  int* Positions = *Arr = (int*)malloc(*n * sizeof(int));

  if(!Positions){
    printf("Failed to malloc Array\n");
    exit(1);
  }

  for(int i=0; i<*n; i++)
    scanf("%d", &Positions[i]);
}

/* Função que busca solução do problema */
int solve(struct solution Sol){
  
  int c = Sol.current;
  
  /* Verifica se o caminho é inválido */ 
  if(c < 0 || c > Sol.nPaths || Sol.usedPaths[c])
    return 0;
  
  /* Verifica se o caminho é solução */
  else if(c == Sol.nPaths-1)
    return 1;

  /* Busca solução */
  else{ // if(c < nPaths-1 || c > 0){
    
    /* Marca posição como "usada" */
    Sol.usedPaths[c] = 1;
    
    /* Procura solução com caminho X */
    Sol.current = c + Sol.paths[c];
    
    if(solve(Sol))
      return 1;
    
    /* Procura solução com caminho Y */ 
    Sol.current = c - Sol.paths[c];
 
    if(solve(Sol))
      return 1; 
  }
  
  return 0;
}
