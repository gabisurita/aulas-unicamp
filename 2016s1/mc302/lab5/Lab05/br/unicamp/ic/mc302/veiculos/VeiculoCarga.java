package br.unicamp.ic.mc302.veiculos;

public class VeiculoCarga extends Veiculo {
	
	Carga carga;
	
	public VeiculoCarga(){
		carga = new Carga();
	}
	
	public void defineCapacidade(int c){
		carga.defineCapacidade(c);
	}
	
	public void display(){
		super.display();
		carga.display();
	}
	
	
	
}
