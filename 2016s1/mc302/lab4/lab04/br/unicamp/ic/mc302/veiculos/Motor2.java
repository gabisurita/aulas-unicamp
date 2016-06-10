package br.unicamp.ic.mc302.veiculos;

public class Motor2 {
	
	private boolean ligado;
	
	private VeiculoMotorizado carro;
	
	public Motor2(VeiculoMotorizado carro){
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
