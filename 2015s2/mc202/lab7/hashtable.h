/* Interface: hashtable.c
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

