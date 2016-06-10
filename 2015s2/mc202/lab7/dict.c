/* Programa: dict.c
 * Autor: Rodrigo Surita (RA 139095)
 *
 * Descrição: Implementa um dicionário de tradução que aceita pares
 * de palavras em diferentes linguagens e permite a busca de 
 * ocorrências a partir da língua mãe.
 *
 */

/* Fator de espalhamento: relação de expansão em memória da tabela de Hash */
#define SPACING_FACTOR 2

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashtable.h"

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


