#include <stdio.h>
#include <stdlib.h>


/* Generic node using char casting. */
typedef struct node {
  
  char* data;
  struct node* next;

} Node;


/* Creates new empty node. */
Node* NewNode(int Size){  
  
  Node* New = malloc(sizeof(Node));
  New->data = malloc(Size);

  New->next = NULL;
  
  return New;
}


/* Writes to a node. */
Node* WriteNode(Node* Inst, int Data){  
  *(Inst->data) = Data;

  return Inst;
}


/* Creates an empty linked list.*/
Node* NewList(int Size, int Length){
  
  Node* Root = NewNode(Size);
  Node* Driver = Root;
  
  for(int i=1; i<Length; i++){
    Driver->next = NewNode(Size);
    Driver = Driver->next;
  }
  
  return Root;
}


/* Append node to a position in the list. */
Node* Append(Node* Root, char* Data, int Size, int Pos){

  Node* Driver = Root;
  
  for(int i=0; i<Pos; i++){
    Driver = Driver->next;  
  }
  
  Node* New = NewNode(Size);
  *(New->data) = *Data; 
  
  return Root;
}


/* Destroy the list. */
void DestroyList(Node* Root){
  while(Root != NULL){
    Node* Last = Root;
    Root = Root->next; 
    free(Last->data);
    free(Last);
  }
}
 

/* Prints the list. */
void PrintList(Node* Root){
  Node* Driver = Root;

  while(Driver != NULL){
    printf("%d\n", *(Driver->data));
    Driver = Driver->next; 
  }
}


int main (){
  printf("Hi\n");
  
  Node* Lista = NewList(sizeof(int), 10);
  PrintList(Lista);
  DestroyList(Lista);
  
  return 0;
}
