/* Programa: avltree.c
 * Autor: Rodrigo Surita (RA: 139095)
 * 
 * Descrição: implementa uma estrutura de árvore binária quase 
 * simétrica do tipo AVL com uma interface simplificada e remoção
 * "preguiçosa" (lazy deletion).
 */


#include <stdio.h>
#include <stdlib.h>

#include "avltree.h"


/* Malloc com verificacao */
void* Smalloc(int mem);

/* Cria uma folha de árvore AVL */
AVLnode* newAVLnode(int key, char* data);

/* Procura um nó AVL com determinada chave a partir de um nó */
AVLnode* selectAVLnode(AVLnode* Root, int key);

/* Rotaciona árvore AVL para à esquerda em torno de um nó */
void rotateLeftAVLnode(AVLnode** Parent);

/* Rotaciona árvore AVL para à direita em torno de um nó */
void rotateRightAVLnode(AVLnode** Parent);

/* Insere um elemento a partir de um nó */
int insertAVLnode(AVLnode** Root, int key, char* data);

/* Destrói um nó AVL e seus decendentes */
void destroyAVLnode(AVLnode** Root);


/* Malloc com verificacao */
void* Smalloc(int mem){
  
  void* Block = malloc(mem);
  if(Block == NULL){
    printf("Malloc Error\n");
    exit(1);
  }
  
  return Block;
}


/* 
 * Operações da estrutura AVL
 *
 */

/* Cria uma folha de árvore AVL */
AVLnode* newAVLnode(int key, char* data){
  
  AVLnode* New = (AVLnode*)Smalloc(sizeof(AVLnode));

  New->key = key;
  
  New->data = data;
 
  New->rig = NULL;
  New->lef = NULL;

  New->bf = 0;

  return New;
}

/* Procura um nó AVL com determinada chave a partir de uma raiz */
AVLnode* selectAVLnode(AVLnode* Root, int key){
  
  if(Root == NULL)
    return NULL;
  
  else if(key < Root->key)
    return selectAVLnode(Root->lef, key);
  
  else if(key > Root->key)
    return selectAVLnode(Root->rig, key);

  else  // (Root->key == key)
    return Root;
  
}

/* Rotaciona árvore AVL para à esquerda em torno de um nó */
void rotateLeftAVLnode(AVLnode** Parent){
  
  AVLnode* a, * b;

  b = *Parent;
  a = b->rig;

  *Parent = a;
  b->rig = a->lef;
  a->lef = b;

}

/* Rotaciona árvore AVL para à direita em torno de um nó */
void rotateRightAVLnode(AVLnode** Parent){

  AVLnode* a, * b;

  b = *Parent;
  a = b->lef;

  *Parent = a;
  b->lef = a->rig;
  a->rig = b;

}

/* Insere elemento como decendente indicando se a árvore aumentou */
int insertAVLnode(AVLnode** Root, int key, char* data){
  
  AVLnode* Iter = *Root;

  /* Novo elemento na posição correta (subárvore vazia) */
  if(Iter == NULL){

    *Root = newAVLnode(key, data);
    return 1;
  }
  
  /* Insere elemento à esquerda */
  else if(key < Iter->key){
    
    int bf = Iter->bf += insertAVLnode(&Iter->lef, key, data);
    
    /* Desbalanceada para o lado contrário (direita) */
    if(bf == 0){
      return 0;  
    }
    /* Árvore balanceada */
    else if(Iter->bf == 0){ 
      return 1;
    }
    /* Desbalanceada para o mesmo lado (esquerda) */  
    else{ // if(Iter->bf < 0){
      rotateRightAVLnode(Root); 
      return 0;
    }
  }
  
  /* Elemento à direita */
  else if(key > Iter->key){
    
    int newlevel = insertAVLnode(&Iter->rig, key, data);

    /* Desbalanceada para o lado contrário (esquerda) */
    if(Iter->bf < 0){
      Iter->bf++;
      return 0;  
    }
    /* Árvore balanceada */
    else if(Iter->bf == 0){
      Iter->bf++;
      return 1;
    }
    /* Desbalanceada para o mesmo lado (direita) */  
    else if(Iter->bf > 0){
      rotateLeftAVLnode(Root); 
      Iter->bf--;
      return 0;
    }
  }
  
  /* Substituir elemento */
  else{
    free(Iter->data);
    Iter->data = data;
    return 0;
  }
  
  return 0;
}  

/* Destrói uma família de nós a partir de um patriarca */
void destroyAVLnode(AVLnode** Root){
  
  AVLnode* Iter = *Root;

  if(Iter == NULL)
   return;

  if(Iter->lef)
    destroyAVLnode(&Iter->lef);

  if(Iter->rig)
    destroyAVLnode(&Iter->rig);

  free(Iter->data);
  free(Iter);
  
  *Root = NULL;
}


/* 
 * Operações da interface
 *
 */

/* Cria árvore AVL */
AVLtree* newAVLtree(){
  
  AVLtree* New = (AVLtree*)Smalloc(sizeof(AVLtree));
  
  New->root = NULL;

  return New;
}

/* Procura os dados de uma entrada em uma árvore AVL */
char* selectAVLtree(AVLtree* Tree, int key){

  if(Tree->root == NULL){
    return NULL;
  }
  else{
    AVLnode* Match = selectAVLnode(Tree->root, key);
    if(Match != NULL){
      if(Match->data != NULL){
         return Match->data;
      }
    }
  }

  return NULL;
}

/* Insere elemento em uma árvore AVL */
void insertAVLtree(AVLtree* Tree, int key, char* data){ 

  insertAVLnode(&Tree->root, key, data); 
}

//* Remoção "preguiçosa" de um elemento em uma árvore AVL */
int removeAVLtree(AVLtree* Tree, int key){
  
  AVLnode* Iter = selectAVLnode(Tree->root, key);
  
  if(Iter != NULL){  
    if(Iter->data != NULL){
      /* Marca o nó como inválido */
      free(Iter->data);
      Iter->data = NULL;
      return key;
    }
  }
  return -1;
}

/* Destrói uma árvore AVL */
void destroyAVLtree(AVLtree* Tree){
    
    destroyAVLnode(&Tree->root);
    free(Tree);
}


