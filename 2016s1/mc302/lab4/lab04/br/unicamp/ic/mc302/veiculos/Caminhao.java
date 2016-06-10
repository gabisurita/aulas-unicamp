package br.unicamp.ic.mc302.veiculos;

public class Caminhao {

	private int numEixos;
	private int capacidade;
	
	public Caminhao(int numEixos, int capacidade){
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
