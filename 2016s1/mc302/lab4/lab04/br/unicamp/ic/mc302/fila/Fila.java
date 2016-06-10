package br.unicamp.ic.mc302.fila;

public class Fila {

	private Lista listaDeElementos;
	
	public Fila(){
		listaDeElementos = new Lista();
	}
	
    public void enfileirar(int i) {
    	listaDeElementos.adicionaFim(i);
        System.out.println("Enfileirou o elemento " + i);
    }
    
    public int pegarPrimeiro() {
        int i = listaDeElementos.removeInicio();
        System.out.println("Tirou o elemento " + i + " do in�cio da fila.");
        return i;
    }

}