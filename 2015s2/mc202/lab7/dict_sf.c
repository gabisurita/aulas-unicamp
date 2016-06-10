/* Programa: dict.c
 * Autor: Rodrigo Surita (RA 139095)
 *
 * Descrição: Versão em arquivo único do programa dict.c. Incluí:
 *  - dict.c
 *  - hashtable.h
 *  - hashtable.c
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* Fator de espalhamento: relação de expansão em memória da tabela de Hash */
#define SPACING_FACTOR 2


/* Interface: hashtable.h
 * Autor: Rodrigo Surita (RA:139095)
 *
 * Descrição: Interface para tabela de espalhameto.
 */

/* Tipo entrada em tabela de espalhamento */
typedef struct hashEntry {
  
  /* Chave de busca de tamanho variável */
  char* key;
  int keySize;
  
  /* Dados */
  char* value;
  int valueSize;

} HashEntry;

/* Tipo abstrato de dados: Tabela de espalhamento */
typedef struct hashTable {
  
  HashEntry* entries;
  int size;

} HashTable;

/* Cria tabela de espalhamento */
HashTable* newHashT(int size);

/* Insere elemento em tabela de espalhamento */
void insertHashT(HashTable* Tab, HashEntry Entry);

/* busca elemento em tabela de espalhamento */
HashEntry queryHashT(HashTable* Tab, HashEntry Query);

/* Destrói tabela de espalhamento da memória */
void destroyHashT(HashTable* Tab);


/* Programa: dict.c
 * Autor: Rodrigo Surita (RA 139095)
 *
 * Descrição: Implementa um dicionário de tradução que aceita pares
 * de palavras em diferentes linguagens e permite a busca de 
 * ocorrências a partir da língua mãe.
 *
 */

//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include "hashtable.h"

/* Tipo: entrada em dicionário */
struct dictEntry{

  char in[16];
  char out[16];
};

/* Tipo: consulta em dicionário */
struct query{

  char word[16];
};

/* Carrega entradas e consultas no dicionário */
void parseInput(int* p, struct dictEntry** Dict, int* c, struct query** Queries);

/* carrega pares de palavras no dicionário */
void loadHashTDict(HashTable* Dict, struct dictEntry* Pairs, int nPairs);

/* Busca ocorrências no dicionário */
void searchHashTDict(HashTable* Dict, struct query* Queries, int nQueries);

int main(){
  
  /* Entradas */
  int nWords;
  int nQueries;

  struct dictEntry* Words;
  struct query* Queries;
  
  /* Carrega entradas */
  parseInput(&nWords, &Words, &nQueries, &Queries);
  
  /* Cria dicionário utilizando tabela de espalhamento */
  HashTable* Dict = newHashT(SPACING_FACTOR * nWords);
  
  /* Carrega pares de palavras no dicionário */
  loadHashTDict(Dict, Words, nWords);
  
  /* Realiza consultas */
  searchHashTDict(Dict, Queries, nQueries);

  /* Encerra o programa */
  free(Words);
  free(Queries);
  destroyHashT(Dict);
  
  return 0;
}

/* Carrega entradas do dicionário e consultas subsequentes */
void parseInput(int* p, struct dictEntry** Dict, int* c, struct query** Queries){
  
  scanf("%d", p);
  
  struct dictEntry* DictReader = *Dict = 
    (struct dictEntry*)malloc(*p*sizeof(struct dictEntry));

  if(!DictReader){
    printf("Memory Error\n");
    exit(1);
  }

  for(int i=0; i<*p; i++){
    scanf("%s %s", (char*)&DictReader[i].in, (char*)&DictReader[i].out);
  }

  scanf("%d", c);

  struct query* QueryReader = *Queries = 
    (struct query*)malloc(*c*sizeof(struct query));

  if(!QueryReader){
    printf("Memory Error\n");
    exit(1);
  }

  for(int i=0; i<*c; i++){
    scanf("%s", (char*)&QueryReader[i].word);
  }
}

/* carrega pares de palavras no dicionário */
void loadHashTDict(HashTable* Dict, struct dictEntry* Pairs, int nPairs){
  
  for(int i=0; i<nPairs; i++){
    
    HashEntry New;
    
    New.key = Pairs[i].in;
    New.value = Pairs[i].out;

    New.keySize = strlen(Pairs[i].in);
    New.valueSize = strlen(Pairs[i].out);
    
    insertHashT(Dict, New); 
  }
}

/* Busca ocorrências no dicionário */
void searchHashTDict(HashTable* Dict, struct query* Queries, int nQueries){
  
  for(int i=0; i<nQueries; i++){
    
    HashEntry Query;

    Query.key = Queries[i].word;
    Query.keySize = strlen(Queries[i].word);

    Query = queryHashT(Dict, Query);
    
    if(Query.value)
      printf("%s\n", Query.value);
    else
      printf("ops\n");
  }
}


/* Programa: hashtable.c
 * Autor: Rodrigo Surita (RA 139095)
 *
 * Descrição: Implementa uma tabela de espalhamento (hash table)
 * utilizando enderençamento aberto.
 *
 */

//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include "hashtable.h"

/* Função de hashing */
int hashFunc(char* data, int size){
  
  unsigned int hash = 0;
  
  for(int i=0; i<size; i++)
    hash = 255*hash + (unsigned int)data[i];
  
  return (int)(hash/2);
}

/* Cria tabela de espalhamento de tamanho arbitário */
HashTable* newHashT(int size){

  HashTable* New = (HashTable*)malloc(sizeof(HashTable));

  if(!New){
    printf("Memory error\n");
    exit(1);
  } 

  New->size = size;
  New->entries = (HashEntry*)calloc(size, sizeof(HashEntry));

  if(!New->entries){
    printf("Memory error\n");
    exit(1);
  } 

  return New;
}

/* Insere ocorrência em tabela de espalhamento */
void insertHashT(HashTable* Tab, HashEntry Entry){

  int hash = hashFunc(Entry.key, Entry.keySize) % Tab->size;
  
  HashEntry EntryPoint = Tab->entries[hash];
  
  /* Busca endereços após ponto de entrada */ 
  for(int i=0; i<Tab->size; i++){
    
    /* Campo vazio: posição de inserção */ 
    if(EntryPoint.key == NULL){

      Tab->entries[hash] = Entry;
      return;
    }

    hash++;
    
    /* Volta ao inicio do vetor caso o fim seja atingido */    
    if(hash == Tab->size)
      hash = 0;
    
    EntryPoint = Tab->entries[hash];
  }
  
  /* Erro: tabela cheia */
  printf("Code error: insert on full hash table\n");
  exit(1);
}

/* Busca entrada em tabela de espalhamento */
HashEntry queryHashT(HashTable* Tab, HashEntry Query){

  int hash = hashFunc(Query.key, Query.keySize) % Tab->size;
  
  HashEntry Search = Tab->entries[hash];
    
  /* Busca endereços após ponto de entrada */ 
  for(int i=0; i<Tab->size; i++){ 
    
    /* Para busca: campo vazio (miss) ou chave encontrada (hit) */
    if(Search.key == NULL || strcmp(Query.key, Search.key) == 0){
      return Search;
    }

    hash++;
    
    /* Volta ao inicio do vetor caso o fim seja atingido */    
    if(hash == Tab->size)
      hash = 0;

    Search = Tab->entries[hash]; 
  }
  
  /* Resultado não encontrado: retorna busca inválida */ 
  Query.value = NULL;

  return Query;
}

/* Libera tabela de Hash da memória */ 
void destroyHashT(HashTable* Tab){
  
  free(Tab->entries);
  free(Tab);
}

