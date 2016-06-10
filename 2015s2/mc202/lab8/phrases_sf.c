/* Programa:  phrases_sf.c
 * Autor: Rodrigo Surita (RA:139095)
 *
 * Descrição: Versão em arquivo único do programa Phrases. Contém:
 *  1.1 mc202.h
 *  1.2 hashtable.h
 *  1.3 heap.h
 *  1.4 oriented_graph.h
 *
 *  2.1 mc202.c
 *  2.2 hashtable.c
 *  2.3 heap.c
 *  2.4 oriented_graph.c
 *  2.5 phrases.c
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Tipo: variável genérica indexada (para estruturas de dados indexadas) */
typedef struct var {

  /* Chave ou índice */
  char* key;
  int id;

  /* Dado ou valor */
  char* data;
  int val;

} Var;


/* Chamada de erro: falha de memória */
void raiseMemoryError(){

  printf("Fatal Memory Error\n");
  exit(1);
}


/* Interface: hashtable.h
 * Autor: Rodrigo Surita (RA:139095)
 *
 * Descrição: Interface para tabela de espalhameto.
 */

/* Tipo abstrato de dados: Tabela de espalhamento */
typedef struct hashTable {
  
  Var* entries;
  int size;

} *HashTable;

/* Cria tabela de espalhamento */
HashTable newHashT(int size);

/* Insere elemento em tabela de espalhamento */
void insertHashT(HashTable Tab, Var Entry);

/* busca elemento em tabela de espalhamento */
Var queryHashT(HashTable Tab, Var Query);

/* Destrói tabela de espalhamento da memória */
void destroyHashT(HashTable Tab);



/* Interface: heap.h
 * Autor: Rodrigo Surita (RA: 139095)
 *
 * Descrição: Tipo abstrato de dados fila de prioridade
 * descrita com uma estrutura abstrata de heap na
 * implementada na forma de vetor de vetor.
 */

typedef struct heap{
  
  int size;
  int count;
  Var* data;

} *Heap; 


/* Restabelece a propriedade de Heap de uma subárvore */
void heapify(Heap Hp, int idx);

/* Cria um Heap vazio de tamanho arbitrário */
Heap newHeap(int size);

/* Insere elemento na Heap com prioridade k */
void pushHeap(Heap Hp, Var data);

/* Retorna o elemento de maior prioridade na Heap */
Var popHeap(Heap Hp);

/* Destrói a Heap */
void destroyHeap(Heap Hp);




/* Interface: oriented_graph.h
 * Autor: Rodrigo Surita (RA 139095)
 *
 * Descrição: Grafo orientado implementado com matriz de
 * adjacências.
 *
 */

/* Tipo: Vértice de grafo */
typedef struct graphVertex {

  int id;
  Var data;

} GraphVertex;

/* Tipo: grafo armazenado com lista de adjacências */
typedef struct graph {

  int size;
  GraphVertex* nodes;
  int** edges;

} *Graph;

/* Cria um grafo de tamanho arbitrário */
Graph newGraph(int size);

/* Libera um grafo da memória */
void destroyGraph(Graph G);

/* Adiciona uma aresta no grafo */
void setEdgeGraph(Graph G, int startId, int endId, int weight);

/* Verifica se há aresta entre dois nós */
int hasEdgeGraph(Graph G, int startId, int endId);

/* Verifica se há caminho entre dois vértices */
int hasPathGraph(Graph G, int startId, int endId);

/* Modifica o conteúdo de um vértice */
void setGraphVertex(Graph G, int id, Var data);

/* Recupera o conteúdo de um vértice */
Var getGraphVertex(Graph G, int id);



/* Programa: hashtable.c
 * Autor: Rodrigo Surita (RA 139095)
 *
 * Descrição: Implementa uma tabela de espalhamento (hash table)
 * utilizando enderençamento aberto.
 *
 */

/* Função de hashing */
int hashFunc(char* data, int size){
  
  int hash = 0;
  
  for(int i=0; i<size; i++)
    hash += (hash * 31) + (int)data[i];
  
  return abs(hash);
}

/* Cria tabela de espalhamento de tamanho arbitário */
HashTable newHashT(int size){

  HashTable New = (HashTable)malloc(sizeof(struct hashTable));

  if(!New){
    printf("Memory error\n");
    exit(1);
  } 

  New->size = size;
  New->entries = (Var*)calloc(size, sizeof(Var));

  if(!New->entries){
    printf("Memory error\n");
    exit(1);
  } 

  return New;
}

/* Insere ocorrência em tabela de espalhamento */
void insertHashT(HashTable Tab, Var Entry){

  int hash = hashFunc(Entry.key, strlen(Entry.key)) % Tab->size;
   
  /* Busca endereços após ponto de entrada */ 
  for(int i=hash; i != hash-1; i++){
    
    Var EntryPoint = Tab->entries[i];
    
    /* Campo vazio: posição de inserção */ 
    if(EntryPoint.key == NULL){
      
      Entry.id = i;
      Tab->entries[i] = Entry;
      return;
    }

    
    /* Volta ao inicio do vetor caso o fim seja atingido */    
    if(hash == Tab->size)
      i = 0;  
  }
  
  /* Erro: tabela cheia */
  printf("Code error: insert on full hash table\n");
  exit(1);
}

/* Busca entrada em tabela de espalhamento */
Var queryHashT(HashTable Tab, Var Query){

  int hash = hashFunc(Query.key, strlen(Query.key)) % Tab->size; 
    
  /* Busca endereços após ponto de entrada */ 
  for(int i=hash; i != hash-1; i++){ 
    
    Var Search = Tab->entries[i];
    
    /* Para busca: campo vazio (miss) */
    if(Search.key == NULL)
      return Search;

    /* Para busca: chave encontrada (hit) */
    if(strcmp(Query.key, Search.key) == 0){
      return Search;
    }
    hash++;
    
    /* Volta ao inicio do vetor caso o fim seja atingido */    
    if(hash == Tab->size)
      hash = 0;
  }
  
  /* Resultado não encontrado: retorna busca inválida */ 
  Query.key = NULL;

  return Query;
}

/* Libera tabela de Hash da memória */ 
void destroyHashT(HashTable Tab){
  
  free(Tab->entries);
  free(Tab);
}



/* Programa: heap.c
 * Autor: Rodrigo Surita (RA: 139095)
 *
 * Descrição: Tipo abstrato de dados fila de prioridade
 * descrita com uma estrutura abstrata de heap na
 * implementada na forma de vetor de vetor.
 */

/* Abstração do vetor para uma árvore */
#define lef(x) 2*x+1
#define rig(x) 2*x+2
#define par(x) (x-1)/2

/* Restabelece a propriedade de Heap de uma subárvore */
void heapify(Heap Hp, int idx);

/* Cria um Heap vazio de tamanho arbitrário */
Heap newHeap(int size){

  Heap New = (Heap)malloc(sizeof(struct heap));

  if(!New){
    printf("Memory error: Failed to malloc Heap\n");
    exit(1);
  }

  New->size = size;
  New->count = 0;
  New->data = (Var*)malloc(size*sizeof(Var));

  if(!New->data){
    printf("Memory error: Failed to malloc Heap->data\n");
    exit(1);
  }

  return New;
}

/* Insere elemento na Heap com prioridade k */
void pushHeap(Heap Hp, Var Data){

  int count = Hp->count;

  if(count == Hp->size){
    printf("Code Error: Invalid push on full Heap\n");
  }

  /* Insere o elemento na última posição */ 
  Hp->data[count] = Data;
  Hp->count++;

  /* Sobe o elemento na árvore */
  for(int idx=count; idx>0; idx=par(idx)){
    Var El = Hp->data[idx];
    Var Parent = Hp->data[par(idx)];

    if(El.id < Parent.id){
      Var Swap = Hp->data[idx];
      Hp->data[idx] = Hp->data[par(idx)];
      Hp->data[par(idx)] = Swap;
    }
    else{
      break;
    }
  }
}

/* Retorna o elemento de maior prioridade na Heap */
Var popHeap(Heap Hp){

  if(!Hp->count){
    printf("Code Error: Invalid Pop request on empty Heap\n");
    exit(1);
  }

  Var Out;

  /* Troca topo pela folha de maior nível mais à direita */
  Hp->count--;
  Out = Hp->data[0];
  Hp->data[0] = Hp->data[Hp->count];

  /* Corrige a árvore */
  heapify(Hp, 0);

  return Out;
}

/* Destrói a Heap */
void destroyHeap(Heap Hp){

  free(Hp->data);
  free(Hp);
}

/* Restabelece a propriedade de Heap de uma subárvore */
void heapify(Heap Hp, int idx){

  Var* Data = Hp->data;

  int maxIndex = idx;

  if(lef(idx) < Hp->count &&
      Data[lef(idx)].id < Data[maxIndex].id)
    maxIndex = lef(idx);

  if(rig(idx) < Hp->count &&
      Data[rig(idx)].id < Data[maxIndex].id)
    maxIndex = rig(idx);

  /* Verifica se o maior indice não é o do pai */
  if(maxIndex != idx){

    /* Troca elemento */
    Var Swap;

    Swap = Data[maxIndex];
    Data[maxIndex] = Data[idx];
    Data[idx] = Swap;

    /* Verifica propriedade para a subárvore menor */
    heapify(Hp, maxIndex);
  }
}



/* Programa: oriented_graph.c
 * Autor: Rodrigo Surita (RA 139095)
 *
 * Descrição: Implementação de grafo orientado utilizando
 * tabela de adjacências.
 *
 */

#define INF 0x7FFFFFFF

/* Função de dijsktra para menor caminho no grafo */
int dijsktra(Graph G, int** Paths, int** Weights, int startId, int endId);

/* Cria um grafo de tamanho arbitrário */
Graph newGraph(int size){
  
  Graph G = (Graph)malloc(sizeof(struct graph));

  if(!G)
    raiseMemoryError();
  
  G->size = size;
  G->nodes = (GraphVertex*)malloc(size*sizeof(GraphVertex));
  G->edges = (int**)malloc(size*sizeof(int*));

  if(!G->nodes || !G->edges)
    raiseMemoryError();

  for(int i=0; i<G->size; i++){
    G->nodes[i].data.key = NULL; 
    G->nodes[i].data.id = -1; 
  
    G->edges[i] = (int*)malloc(size*sizeof(int));

    for(int j=0; j<G->size; j++)
      G->edges[i][j] = INF;
  }

  return G;
}

/* Libera um grafo da memória */
void destroyGraph(Graph G){
  
  for(int i=0; i<G->size; i++)
   free(G->edges[i]);

  free(G->edges);
  free(G->nodes);
  free(G);
}

/* Adiciona uma aresta no grafo */
void setEdgeGraph(Graph G, int startId, int endId, int weight){
  
  if(startId < 0 || startId >= G->size){
    printf("Code Error: Invalid Egde start id\n");
    exit(1);
  }
  
  if(startId < 0 || startId >= G->size){
    printf("Code Error: Invalid Egde end id\n");
    exit(1);
  }
  
  G->edges[startId][endId] = weight;
}

/* Remove aresta no grafo */
void removeEdgeGraph(Graph G, int startId, int endId){

  G->edges[startId][endId] = 0;
}

/* Modifica o conteúdo de um vértice */
void setGraphVertex(Graph G, int id, Var data){
  
  if(id < 0 || id >= G->size){
    printf("Code Error: Invalid setGraph id\n");
    exit(1);
  }

  G->nodes[id].data = data; 
}

/* Recupera o conteúdo de um vértice */
Var getGraphVertex(Graph G, int id){
  
  return G->nodes[id].data;
}

/* Encontra lista de vértices do menor caminho entre dois nós */
int* getPathVertex(Graph G, int startId, int endId){
  
  int* Paths;
  int* Weights;  

  int dist = dijsktra(G, &Paths, &Weights, startId, endId);
  
  
  if(dist == INF){
    
    free(Weights);
    free(Paths);
    
    return NULL;
  }
  
  int* revSeq = Weights;

  int last = endId;
  int i = 0;

  while(last != startId){
    revSeq[i] = last;
    last = Paths[last];
    i++;
  }
   
  int* Seq = Paths;
  Seq[0] = startId;

  for(int j=1; j<=i; j++)
    Seq[j] = revSeq[i-j];
  

  free(Weights);
  
  return Seq;
}

/* Função de dijsktra para menor caminho no grafo */
int dijsktra(Graph G, int** Paths, int** Weights, int startId, int endId){ 

  int* Dists = *Weights = (int*)malloc(G->size*sizeof(int)); 
  int* Lasts = *Paths = (int*)malloc(G->size*sizeof(int));
  
  if(!Dists || !Lasts)
    raiseMemoryError();

  Heap Prior = newHeap(G->size*G->size);

  for(int i=0; i<G->size; i++){

    Dists[i] = INF;
    Lasts[i] = -1;  
  }

  Dists[startId] = 0;
  
  for(int i=0; i<G->size; i++){

    Var New;
    
    New.id = Dists[i];
    New.val = i;
    
    pushHeap(Prior, New);
  } 
  
  while(Prior->count > 0){
    
    int i = popHeap(Prior).val;
    
    for(int j=0; j<G->size; j++){

      if(G->edges[i][j] == INF || Dists[i] == INF)
        continue;
   
      if(Dists[j] > Dists[i] + G->edges[i][j]){
        
         Dists[j] = Dists[i] + G->edges[i][j];
         Lasts[j] = i; 
         
         Var New; 
         New.id = Dists[j];
         New.val = j;
         
         pushHeap(Prior, New);
      }
    }
  }

  int dist = Dists[endId];
  
  destroyHeap(Prior);

  return dist;
}



/* Programa: phrase_generator.c
 * Autor: Rodrigo Surita (RA: 139095)
 *
 * Descrição:
 *
 */

typedef struct phrase {

  char** words;
  int nWords;

} Phrase;

/* Carrega entradas do grafo */
void parseInputs(int*p, int* M, int* n, Phrase** Phrases);

/* Carrega consultas no grafo */
void parseQueries(int* c, Phrase** Queries);

int main(){
  
  /* Entradas do grafo */    
  int mWeight;
  int pWords;  
  int nPhrases;
  Phrase* Phrases;

  /* Carrega entradas */  
  parseInputs(&pWords, &mWeight, &nPhrases, &Phrases);

  /* Grafo de relações entre palavras */
  Graph G = newGraph(pWords);
  
  /* Tabela de chaveamento entre palavras e id's no grafo */  
  HashTable Tab = newHashT(5*pWords); // espalhamento de ordem 5

  int wordId = 0;
  int lastId = 0;

  /* Adiciona palavras no grafo */
  for(int i=0; i<nPhrases; i++){
  
    for(int j=0; j<Phrases[i].nWords; j++){

      Var New;
      New.key = Phrases[i].words[j];
     
      /* Verifica se a palavra já está mapeada na tabela */
      Var Q = queryHashT(Tab, New);
      
      /* Caso 1: palavra já mapeada */
      if(Q.key){
        
        /* Condição: palavra não é inicio de frase */
        if(j != 0){
          
          /* Caso 1.1: não há relação entre a palavra mapeada e a anterior */ 
          if(G->edges[lastId][Q.val] < INF)
            G->edges[lastId][Q.val]--;
          
          /* Caso 1.2: há relação entre a palavra mapeada e a anterior */ 
          else 
            G->edges[lastId][Q.val] = mWeight - 1;
        }
        
        lastId = Q.val; 
      }
      
      /* Caso 2: palavra não mapeada */
      else{
        
        /* Define o id da palavra*/
        New.val = wordId;
        
        /* Mapeia o id da palavra na tabela */
        insertHashT(Tab, New);

        /* Cria nó no grafo para o ID em questão */
        setGraphVertex(G, wordId, New);

        /* Condição: palavra não é inicio de frase */
        if(j != 0){
       
          /* Adiciona mapeamento da palavra anterior */
          G->edges[lastId][wordId] = mWeight - 1;
        }

        lastId = wordId;
        wordId++;
      }
    }
  }


  /* Consultas */
  int nQueries;
  Phrase* Queries;
  
  /* Carrega consultas */
  parseQueries(&nQueries, &Queries);

  /* Procura sentenças válidas */
  for(int i=0; i<nQueries; i++){
  
    char* Start = Queries[i].words[0]; 
    char* End   = Queries[i].words[1];
    
    int startId;
    int endId;
    
    /* Busca id da primeira palavra */
    Var Query;
    Query.key = Start;
    Query = queryHashT(Tab, Query);
    
    if(!Query.key){
      printf("erro\n");
      continue;
    }
    
    startId = Query.val;

    /* Busca id da última palavra */
    Query.key = End;
    Query = queryHashT(Tab, Query);
    
    if(!Query.key){
      printf("erro\n");
      continue;
    }
  
    endId = Query.val;
    
    /* Busca caminho entre as duas palavras */
    int* Path = getPathVertex(G, startId, endId); 
    
    /* Caso: existe caminho */
    if(Path){
    
      int i;
      
      /* Imprime o caminho */
      for(i=0; Path[i] != endId; i++)
         printf("%s ", G->nodes[Path[i]].data.key);
      printf("%s\n", G->nodes[Path[i]].data.key);
      
      free(Path);
    } 
    
    /* Caso: não existe caminho (imprime erro) */
    else{
      printf("erro\n");
    }
  }

  /* Libera entradas do grafo da memória */
  for(int i=0; i<nPhrases; i++){
    
    for(int j=0; j<Phrases[i].nWords; j++)
      free(Phrases[i].words[j]);
    
    free(Phrases[i].words);
  }

  free(Phrases);

  /* Libera consultas da memória */
  for(int i=0; i<nQueries; i++){
    
    for(int j=0; j<Queries[i].nWords; j++)
      free(Queries[i].words[j]);
    
    free(Queries[i].words);
  }

  free(Queries);
  
  destroyGraph(G);
  destroyHashT(Tab);

  return 0;
}

/* Carrega entradas do grafo */
void parseInputs(int* p, int* M, int* n, Phrase** Phrases){
  
  scanf("%d %d %d", p, M, n);

  Phrase* Iter = *Phrases = (Phrase*)malloc(*n*sizeof(Phrase));
  
  if(!Iter)
    raiseMemoryError();

  for(int i=0; i<*n; i++){
    
    int l;
    scanf("%d", &l);
    
    Iter[i].nWords = l;
    Iter[i].words = (char**)malloc(l*sizeof(char*));


    if(!Iter[i].words)
      raiseMemoryError();

    for(int j=0; j<l; j++){
      
      char word[32];
      scanf("%s", word);

      Iter[i].words[j] = (char*)malloc((strlen(word)+1)*sizeof(char));
      strcpy(Iter[i].words[j], word);
    }
  }
}

/* Carrega consultas no grafo */
void parseQueries(int* c, Phrase** Queries){

  scanf("%d", c);

  Phrase* Iter = *Queries = (Phrase*)malloc(*c*sizeof(Var));
  
  if(!Iter)
    raiseMemoryError();

  for(int i=0; i<*c; i++){
    
    Iter[i].nWords = 2;
    Iter[i].words = (char**)malloc(2*sizeof(char*));


    if(!Iter[i].words)
      raiseMemoryError();

    for(int j=0; j<2; j++){
      
      char word[32];
      scanf("%s", word);

      Iter[i].words[j] = (char*)malloc((strlen(word)+1)*sizeof(char));
      strcpy(Iter[i].words[j], word);
    }
  }
}

