/* Interface: avltree.h
 * Autor: Rodrigo Surita (RA: 139095)
 * 
 * Descrição: interface para árvore AVL.
 */


/* T.A.D. nó AVL */
typedef struct AvlNode {
  
  int key;
  int bf;
  
  struct AvlNode* lef;
  struct AvlNode* rig; 

  char* data;

} AVLnode;

/* Tipo árvore AVL (simplifica a interface) */
typedef struct avlTree {

  AVLnode* root;

} AVLtree;

/* Cria árvore AVL */
AVLtree* newAVLtree();

/* Procura os dados de uma entrada em uma árvore AVL */
char* selectAVLtree(AVLtree* Tree, int key);

/* Insere elemento em uma árvore AVL */
void insertAVLtree(AVLtree* Tree, int key, char* data); 

/* Remove elemento em uma árvore AVL */
int removeAVLtree(AVLtree* Tree, int key); 

/* Destrói uma árvore AVL */
void destroyAVLtree(AVLtree* Tree);


