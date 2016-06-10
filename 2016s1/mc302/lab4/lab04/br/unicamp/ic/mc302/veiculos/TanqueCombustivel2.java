package br.unicamp.ic.mc302.veiculos;

public class TanqueCombustivel2 {

	private int volume;
	private int capacidade;
	private VeiculoMotorizado carro;
	
	public TanqueCombustivel2(VeiculoMotorizado carro){
		volume = 0;
		this.carro = carro;
	}

	public void encher(int vol){
		
		volume += vol;
		
		if(volume > capacidade){
			volume = capacidade;
		}
	}
	
	public int leitura(){
		return volume;
	}
	
	public void gastar(int vol){
		volume -= vol;
		
		if(volume < 0){
			volume = 0;
			carro.desligar();
		}
	}

}
