/* Programa: phrase_generator.c
 * Autor: Rodrigo Surita (RA: 139095)
 *
 * Descrição:
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mc202.h"
#include "hashtable.h"
#include "oriented_graph.h"

/* Tipo: Palavra */
typedef struct word {

  char text[31];

} Word;

/* Tipo: Frase com n palavras */
typedef struct phrase {

  Word* words;
  int nWords;

} Phrase;

/* Carrega entradas do grafo */
void parseInputs(int *p, int* M, int* n, Phrase** Phrases);

/* Carrega consultas no grafo */
void parseQueries(int* c, Phrase** Queries);

int main(){
  
  /* Entradas do grafo */    
  int nWords;
  int mWeight;
  int nPhrases;
  Phrase* InputPhrases;
  
  parseInputs(&nWords, &mWeight, &nPhrases, &InputPhrases);
  
  /* Consultas */
  int nQueries;
  Phrase* Queries;
  
  parseQueries(&nQueries, &Queries);

  Graph G = newGraph(nWords);
  HashTable Tab = newHashT(nWords);
  
  int wordId = 0;

  for(int i=0; i<nPhrases; i++){ 
    for(int j=0; j<InputPhrases[i].nWords; j++){
      
      Word W = InputPhrases[i].words[j];
      
      HashEntry Entry;
      
      Entry.key = W.text;
      Entry.keySize = strlen(W.text);
      Entry.value = NULL;
      Entry.valueSize = wordId;

      insertHashT(Tab, Entry);
      setGraphVertex(G, wordId, NULL); 
    }
  }


  

  /* Libera entradas do grafo da memória */
  for(int i=0; i<nPhrases; i++)
    free(InputPhrases[i].words);
  
  free(InputPhrases);

  /* Libera consultas da memória */
  for(int i=0; i<nQueries; i++)
    free(Queries[i].words);
  
  free(Queries);
  
  destroyGraph(G);

  return 0;
}

/* Carrega entradas do grafo */
void parseInputs(int* p, int* M, int* n, Phrase** Phrases){
  
  scanf("%d %d %d", p, M, n);

  Phrase* Iter = *Phrases = (Phrase*)malloc(*n*sizeof(Phrase));
  
  if(!Iter)
    raiseMemoryError();

  for(int i=0; i<*n; i++){
    
    int p;
    scanf("%d", &p);
    
    Iter[i].nWords = p;
    Iter[i].words = (Word*)malloc(p*sizeof(Word));
    
    if(!Iter[i].words)
      raiseMemoryError();

    for(int j=0; j<p; j++)
      scanf("%s", (char*)&Iter[i].words[j].text);
  }
}

/* Carrega consultas no grafo */
void parseQueries(int* c, Phrase** Queries){

  scanf("%d", c);

  Phrase* Iter = *Queries = (Phrase*)malloc(*c*sizeof(Phrase));
  
  if(!Iter)
    raiseMemoryError();

  for(int i=0; i<*c; i++){
    
    Iter[i].nWords = 2;
    Iter[i].words = (Word*)malloc(2*sizeof(Word));
    
    if(!Iter[i].words)
      raiseMemoryError();

    for(int j=0; j<2; j++)
      scanf("%s", (char*)&Iter[i].words[j].text);
  }
}
