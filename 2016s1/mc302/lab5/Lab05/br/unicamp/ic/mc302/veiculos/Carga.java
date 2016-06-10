package br.unicamp.ic.mc302.veiculos;

public class Carga {
	
	private int capacidade;

	public void defineCapacidade(int c){
		capacidade = c;
	}
	
	public void display(){
		System.out.println("Capacidade de Carga: "+capacidade);
	}

}
