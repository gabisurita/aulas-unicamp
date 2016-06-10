package br.unicamp.ic.mc302.veiculos;

public class Caminhao2 extends VeiculoMotorizado {

	private int numEixos;
	private int capacidade;
	
	public Caminhao2(int lot, int num, int ano, String mar, String mod, String pl, int numEixos, int capacidade){
		
		super(lot, num, ano, mar, mod, pl);
		this.numEixos = numEixos;
		this.capacidade = capacidade;
	}
	
	public int numeroDeEixos(){
		return numEixos;
	}
	
	public int capacidadeMaxima(){
		return capacidade;
	}
}
