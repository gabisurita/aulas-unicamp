#include <stdio.h>
#include <stdlib.h>



/********************************************************************
Programa: queue.h
Autor: Rodrigo Surita (RA:139095)

Descricao: Define um tipo abstrado de dados fila utilizando listas
ligadas circulares.
********************************************************************/



/* Define um tipo no com valor inteiro. */
typedef struct node {
  int val;
  struct node* next;
} Node;



/* Define um tipo fila */
typedef struct queue {
  Node* start;
  Node* end;
} Queue;



/* Malloc com verificacao */
void* Smalloc(int Size);

/* Cria uma fila */
Queue* NewQueue();
  
/* Insere elemento na entrada da fila */
void InQueue(Queue** Qe, int val);

/* Retira elemento da saida da fila */
int OutQueue(Queue** Queue);

/* Verifica se a lista possui elementos */
int NotNullQueue(Queue** Qe);

/* Libera fila da memoria. */
void DestroyQueue(Queue** Qe);

/* Cria um tipo no com valor arbitrario */
Node* NewNode(int Val);



/********************************************************************
Programa: queue.c
Autor: Rodrigo Surita (RA:139095)

Descricao: Implementa um tipo abstrado de dados fila utilizando 
listas ligadas circulares.

********************************************************************/


/* Malloc com verificacao */
void* Smalloc(int Size){
  
  void* Mem = malloc(Size);
  if(Mem == NULL){
    printf("Malloc Error\n");
    exit(1);
  }
  
  return Mem;
}


/* Cria um tipo no com valor arbitrario */
Node* NewNode(int Val){

  Node* New = (Node*)Smalloc(sizeof(Node));
  New->val = Val;

  return New;
}



/* Libera (no a no) uma lista da memoria. */
void DestroyList(Node** Root){

  Node* Next;
  Node* Iter = *Root;

  
  while(Iter != NULL){
    Next = Iter->next;
    free(Iter);
    Iter = Next;
  }
}


/* Cria umq fila */
Queue* NewQueue(){

  Queue* Qe = Smalloc(sizeof(Queue));
  Qe->start = NULL;
  Qe->end = NULL;
  return Qe;

}



/* Insere elemento na entrada da fila */
void InQueue(Queue** Qe, int val){  
  
  Queue* Iter = *Qe;
  
  Node* New = NewNode(val);  
  
  if(Iter->end){
    New->next = Iter->start;
    Iter->end->next = New;
    Iter->end = New;
  }
  else{
    Iter->start = New;
    Iter->end = New;
    Iter->end->next = New;
  }
}



/* Retira elemento da saida da fila */
int OutQueue(Queue** Qe){

  Node* OutNode;
  int OutValue;
  Queue* Iter = *Qe;

  OutNode = Iter->start;

  if(Iter->end != Iter->start){
    Iter->start = Iter->start->next;    
  }
  else{
    Iter->start = NULL;
    Iter->end = NULL;
  }
  
  OutValue = OutNode->val;
  
  free(OutNode);
  
  return OutValue;  
}


/* Verifica se a lista possui elementos */
int NotNullQueue(Queue** Qe){
  return (*Qe)->end != NULL;
}


/* Libera fila da memoria. */
void DestroyQueue(Queue** Qe){
  
  while(NotNullQueue(Qe)){
    OutQueue(Qe);
  }
  
  free(*Qe);
}



/********************************************************************
Programa: array.h
Autor: Rodrigo Surita (RA:139095)

Descricao: Define algumas operaçoes com arrays de inteiros.
********************************************************************/


/* Retorna indice da primeira ocorrencia de menor valor num array */
int MinArrayId(int Arr[], int Size);

/* Retorna o elemento de maior valor em um array */
int MaxArray(int Arr[], int Size);

/* Ordena um Array e usando o algoritimo BubbleSort, mantendo um
indice da posicao original dos elementos */
void BubbleSortIds(int** Ids, int Arr[], int nT);



/********************************************************************
Programa: array.c
Autor: Rodrigo Surita (RA:139095)

Descricao: Define algumas operaçoes com arrays de inteiros.
********************************************************************/

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



/********************************************************************
Programa: alloc.c
Autor: Rodrigo Surita (RA:139095)

Descricao: realiza a alocacao de tarefas prevista pelo algoritimo 
especificado na atividade 01 de MC202, descrita em [1], utilizando 
filas implementadas com listas ligadas disponiveis na biblioteca 
"queue.h" desenvolvida.

[1] https://susy.ic.unicamp.br:9999/mc202gh/01/lab01.pdf

********************************************************************/


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


