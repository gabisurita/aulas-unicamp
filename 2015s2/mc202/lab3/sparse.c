#include <stdio.h>
#include <stdlib.h>


typedef struct node {

  char val;

  int lin;
  int col;
  
  struct node* right;
  struct node* down;

} Node;



typedef struct sparse {

  int m;
  int n;
  
  Node** cols;
  Node** lins;
} Sparse;



void NewNode(Node** New){
  
  *New = (Node*)malloc(sizeof(Node));

  if(!New){
    printf("Memory Boooom\n");
    exit(1);
  }
}


void DestroyNodeChildren(Node** Curr){

  Node* Iter = *Curr;
  
  if(!Iter){
    return;
  }
    
  if(Iter->right != Iter)
    DestroyNodeChildren(&Iter->right);
  
  if(Iter->down != Iter)
    DestroyNodeChildren(&Iter->down);
  
  free(Iter);
}
  


void NewSparse(Sparse** New, int m, int n){

  int i;

  Sparse* Iter = *New = (Sparse*)malloc(sizeof(Sparse));

  if(!New){
    printf("Memory Boooom\n");
    exit(1);
  }
 
  Iter->m = m;
  Iter->n = n;
  
  Node** lins = Iter->lins = (Node**)malloc(m*sizeof(Node*));
  Node** cols = Iter->cols = (Node**)malloc(n*sizeof(Node*));

  for(i=0; i<m; i++){
    NewNode(&lins[i]);
    lins[i]->right = lins[i];
    lins[i]->down  = NULL;
/*    lins[i]->lin = i;*/
/*    lins[i]->col = -1;*/
  }

  for(i=0; i<n; i++){
    NewNode(&cols[i]); 
    cols[i]->right = NULL;
    cols[i]->down  = lins[i];
/*    lins[i]->lin = -1;*/
/*    lins[i]->col = i;*/
  }
}


void DestroySparse(Sparse* Mat){

  int i;

  int m = Mat->m;
  int n = Mat->n;


  for(i=0; i<m; i++)
    DestroyNodeChildren(&Mat->lins[i]);

  for(i=0; i<n; i++)
    free(Mat->cols[i]);

  free(Mat->lins);
  free(Mat->cols);
  free(Mat);
}


Node* LinSparse(Sparse* Mat, int lin){
  
  return Mat->lins[lin];
}


Node* ColSparse(Sparse* Mat, int col){
  
  return Mat->cols[col];
}


char GetElSparse(Sparse* Mat, int lin, int col){  

  Node* LinHead = LinSparse(Mat, lin);
  Node* ColHead = ColSparse(Mat, col);

  Node* IterLin = LinHead->right;
  Node* IterCol = ColHead->down;

  while(IterLin->right != LinHead && col > IterLin->col){
    IterLin = IterLin->right;
  }

  while(IterCol->down != ColHead && lin > IterCol->lin){
    IterCol = IterCol->down;
  }

  if(lin == IterLin->lin && col == IterCol->col){
    printf("Has found? %d\n", IterLin == IterCol);
    printf("IterLin: %d\nIterCol: %d\n\n", IterLin->lin, IterCol->col);
    printf("Value: %d\n\n", IterCol->val);
    return IterCol->val;
  }
  
  else{
    printf("IterLin: %d\nIterCol: %d\n\n", IterLin->lin, IterCol->col);
    return -1;  
  }
}


void SetSparse(Sparse* Mat, char val, int lin, int col){  
  printf("SetSparse(val=%d, lin=%d, col=%d)\n", val, lin, col);
  Node* New;  
  
  Node* LinHead = LinSparse(Mat, lin);
  Node* ColHead = ColSparse(Mat, col);

  Node* IterLin = LinHead->right;
  Node* IterCol = ColHead->down;

  while(IterLin->right != LinHead && lin > IterLin->lin){
    IterLin = IterLin->right;
    printf("!");
  }

  while(IterCol->down != ColHead && col > IterCol->col){
    IterCol = IterCol->down;
  }

  if(lin == IterLin->lin && col == IterCol->col){
    IterLin->val = val;
  }
  
  else{
    NewNode(&New);
    
    New->val = val;
    New->lin = lin;
    New->col = col;
    
    New->right = IterLin->right;
    New->down  = IterCol->down;
    
    IterLin->right = New;
    IterCol->down  = New;
  }


  printf("Has found? %d\n", IterLin == IterCol);
  printf("IterLin: %d\nIterCol: %d\n\n", IterLin->lin, IterCol->col);
  printf("Value: %d\n\n", IterCol->val);

}


int main(){

  Sparse* Mat;

  NewSparse(&Mat, 5,5);
  for(int i=0; i<5; i++){
    SetSparse(Mat, '*', i,i);
  }
  
  GetElSparse(Mat, 1,1);
  
  DestroySparse(Mat);

  return 0;
}
