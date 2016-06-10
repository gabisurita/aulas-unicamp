package br.unicamp.ic.mc302.veiculos;

public class Motor {
	
	private boolean ligado;
	
	private Carro carro;
	
	public Motor(Carro carro){
		this.carro = carro;
	}
	
	public void ligar(){
		ligado = true;
	}
	
	public void desligar(){
		ligado = false;
	}
	
	public boolean estaLigado(){
		return ligado;
	}
	
}
