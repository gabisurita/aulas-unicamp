/* Programa: hashtable.c
 * Autor: Rodrigo Surita (RA 139095)
 *
 * Descrição: Implementa uma tabela de espalhamento (hash table)
 * utilizando enderençamento aberto.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashtable.h"


int hashFunc(char* data, int size){
  
  int hash = 0;
  
  for(int i=0; i<size; i++)
    hash += (hash * 31) + (int)data[i];
  
  return hash;
}

/* Cria tabela de espalhamento de tamanho arbitário */
HashTable newHashT(int size){

  HashTable New = (HashTable)malloc(sizeof(struct hashTable));

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
void insertHashT(HashTable Tab, HashEntry Entry){

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
HashEntry queryHashT(HashTable Tab, HashEntry Query){

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
void destroyHashT(HashTable Tab){
  
  free(Tab->entries);
  free(Tab);
}

