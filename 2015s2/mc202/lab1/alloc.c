/********************************************************************
Programa: alloc.c
Autor: Rodrigo Surita (RA:139095)

Descricao: realiza a alocacao de tarefas prevista pelo algoritimo 
especificado na atividade 01 de MC202, descrita em [1], utilizando 
filas implementadas com listas ligadas disponiveis na biblioteca 
"queue.h" desenvolvida.

[1] https://susy.ic.unicamp.br:9999/mc202gh/01/lab01.pdf

********************************************************************/


#include <stdio.h>
#include <stdlib.h>

#include "queue.h"
#include "array.h"



/* Transforma a entrada nos valores alocados em memoria. */
void InputParse(int* nM, int* nT, int** Tasks);

/* Template de formatacao da saida */
void PrintOutput(Queue** Machines, int* MachineSums, int nM);




int main(){

  /* Numeros de maquinas e de tarefas */
  int nM, nT;
  
  /* Arrays de tarefas e de soma de tarefas/maquina */
  int* Tasks;
  int* MachineSums;
  
  /* Array de indices das tarefas */
  int* OrderedTaskIds;

  /* Array de filas para a lista de tarefas das maquinas */
  Queue** Machines;
  
  /* Id da maquina menos requisitada */
  int MinId;
  
  int i;
  
  
  /* Carrega as entradas */
  InputParse(&nM, &nT, &Tasks);

  /* Alocacao de memoria dos arrays */
  Machines = (Queue**)Smalloc((nM)*sizeof(Queue*));
  MachineSums = (int*)Smalloc(nM*sizeof(int));
  OrderedTaskIds = (int*)Smalloc(nT*sizeof(int));

  /* Inicializa uma fila para cada maquina */  
  for(i=0; i<nM; i++){
    Machines[i] = NewQueue();
  }  
  
  /* Inicializa o array de soma de tarefas com 0's */
  for(i=0; i<nM; i++){
    MachineSums[i] = 0;
  }
  
  /* Inicializa o array de indices com sequencia descrescente */
  for(i=nT-1; i>=0; i--){
    OrderedTaskIds[i] = i;
  }  
  
  /* Obtem ordem e indices de tarefas (decrescente) */
  BubbleSortIds(&OrderedTaskIds, Tasks, nT);
  
  /* Alocacao das tarefas em ordem decrescente de tempo */
  for(i=0; i<nT; i++){       
    /* Obtem o indice da maquina menos ocupada */
    MinId = MinArrayId(MachineSums, nM);
    
    /* Atribui a tarefa a maquina menos ocupada */
    MachineSums[MinId] += Tasks[i];
    InQueue(&Machines[MinId], OrderedTaskIds[i]);
  }
  
  /* Imprime o template de saida */
  PrintOutput(Machines, MachineSums, nM);
  
  /* Libera a memoria */
  for(i=0; i<nM; i++){
    DestroyQueue(&Machines[i]);
  }
  
  free(Tasks);
  free(OrderedTaskIds);
  free(MachineSums);
  free(Machines);
  
  return 0;
}





/* Transforma a entrada nos valores alocados em memoria. */
void InputParse(int* nM, int* nT, int** Tasks){
  
  int i;
  
  scanf("%d%d", nM, nT);

  *Tasks = (int*)malloc((*nT)*sizeof(int));
  
  for(i=0; i<*nT; i++){
    scanf("%d", &(*Tasks)[i]);
  }
}



/* Template de formatacao da saida */
void PrintOutput(Queue** Machines, int* MachineSums, int nM){
  int i;
  
  Queue* Qe;
  
  printf("%d\n", MaxArray(MachineSums, nM));

  
  for(i=0; i<nM; i++){
    printf("M%d", i+1);
    
    Qe = Machines[i];    
    
    while(NotNullQueue(&Qe)){  
      printf(" %d", OutQueue(&Qe)+1);
    }
    printf("\n");
  }
}

