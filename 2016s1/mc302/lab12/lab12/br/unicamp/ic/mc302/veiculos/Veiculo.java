package br.unicamp.ic.mc302.veiculos;

import br.unicamp.ic.mc302.motor.Motor;

public class Veiculo {

	private Motor motor;
	private EstadoVeiculo estado;
	
	public Veiculo() {	
		motor = new Motor();
		estado = new VeiculoTerrestre();
	}
	
	public void ligar() {
		
		motor.ligar();
		System.out.println("--- carro ligado ---");
	}
	
	public void andar(){
		estado.andar();
	}
	
	public void mudarEstado(){
		
		if(estado instanceof VeiculoTerrestre)
			estado = new VeiculoMaritimo();
		
		else
			estado = new VeiculoTerrestre();
	}

}