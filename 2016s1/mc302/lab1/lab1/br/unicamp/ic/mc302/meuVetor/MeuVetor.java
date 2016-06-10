package br.unicamp.ic.mc302.meuVetor;

class MeuVetor {
	
	public int tam;
	private int[] val;

	public void inicializa(int chave, int valor){
		val[chave] = valor;
	}
	
	public MeuVetor intercala(MeuVetor par){
		
		int min;
		
		// Define o menor limite
		if(tam >= par.tam)
			min = par.tam;
		else
			min = tam;

		MeuVetor inter = new MeuVetor(2*min);
		
		for(int i=0; i<min; i++){
			inter.inicializa(2*i, val[i]);
			inter.inicializa(2*i+1, par.val[i]);
		}
		
		return inter;
	}
	
	public void imprime(){
		
		for(int i=0; i<tam; i++){
			System.out.print(val[i] + " ");	
		}
		
		System.out.println("");
	}
	
    public MeuVetor(int tamanho){
  
    	tam = tamanho;
    	val = new int[tam];
    }
    
}