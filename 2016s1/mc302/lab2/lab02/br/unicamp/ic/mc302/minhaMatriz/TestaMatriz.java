package br.unicamp.ic.mc302.minhaMatriz;

class TestaMatriz {
	
    public static void main (String [] args) {
    	
    	// Valores das matrizes
    	int Aval[][] = {{0,1,2},{3,4,5}};
    	int Bval[][] = {{1,1},{0,0},{0,0}};
    	
    	// Cria Matrizes
    	MinhaMatriz MatA = new MinhaMatriz(Aval);
    	MinhaMatriz MatB = new MinhaMatriz(Bval);
    	
    	// Exibe o produto
    	MatA.prod(MatB).print();
    	
    }
}

