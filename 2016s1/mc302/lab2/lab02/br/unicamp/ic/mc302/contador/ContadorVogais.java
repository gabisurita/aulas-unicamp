package br.unicamp.ic.mc302.contador;

// Arquivo ContadorVogais.java
public class ContadorVogais {

    public static void main(String args[]) {
	    char fraseExaminada[] = {'T','e','x','t','o',' ','E','x','e','m','p','l','o',' ','P','a','r','a',' ','A',' ','C','o','n','t','a','g','e','m',' ','D','o',' ','N','u','m','e','r','o',' ','D','e',' ','V','o','g','a','i','s','.'};
		Contador[] contVogais = new Contador[5]; // um para cada vogal
	    
		// Definicao das vogais
		char vogaisMai[] = {'A','E','I','O','U'};
		char vogaisMin[] = {'a','e','i','o','u'};
		
		// Inicializa contadores
		for(int i=0; i<5; i++){
			contVogais[i] = new Contador();
	    	contVogais[i].comeca(0);
		}
	    
	    for(int i = 0; i< fraseExaminada.length; i++){
	    	// analisar cada índice do vetor de caracteres fraseExaminada[i] e, se for o caso, 
	    	// incrementar o contador da respectiva vogal	    	
	    	for(int j=0; j<contVogais.length; j++){
	    		if(fraseExaminada[i]==vogaisMai[j] || fraseExaminada[i]==vogaisMin[j]){
	    			contVogais[j].incrementa();
	    		}
	    	}	
	    }
	    
	    // Imprime resultados
	    for(int i=0; i<contVogais.length; i++){
	    	System.out.println(vogaisMai[i] + " " +contVogais[i].retornaNum());
	    }
    }
    
} // Fim da classe ContadorVogais
