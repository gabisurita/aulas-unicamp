#include <iostream>
#include <string>
#include <queue>

#define LIMIT 1000
#define SHIPS 26
#define CHARINF 127
using namespace std;

class Dock{
  
  private:

    priority_queue<int> topOrder;
    char tops[SHIPS];  
    int used;

  public:
    /* Gerador */
    Dock(){
      
      used = 0;
      
      /* Todas as pilhas com prioridade minima */
      for(int i=0; i<SHIPS; i++){
        tops[i]=CHARINF;
      }
    }
    
    /* Empilha sequencia */
    void pile(string sequence){

      /* Para cada elemento da sequencia */
      for(int i=0; i<sequence.size(); i++){
        
        queue<int> usedTops;
        
        /* Para cada pilha viavel */
        for(int j=0; j<topOrder.size(); j++){
          
          char top = topOrder.pop(); 
          


          /* Verifica se a pilha é conflituosa */
          if(sequence[i] <= tops[j]){
            tops[j] = sequence[i];
            
            /* Pilha ainda não usada */ 
            if(j == used)
              used++;
            
            break;
          }
        }
      } 
    }
    
    /* Retorna o numero de pilhas usadas */
    int usedPiles(){
      return used;
    } 
};


int main(){
  
  /* Entrada */
  string containerOrder; 
  getline(cin, containerOrder);

  Dock mos;
  mos.pile(containerOrder);
  
  /* Saida */
  cout << mos.usedPiles();
  cout << "\n";  

  return 0;
}
