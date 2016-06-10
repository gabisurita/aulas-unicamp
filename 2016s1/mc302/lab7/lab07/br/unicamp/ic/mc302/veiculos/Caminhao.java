package br.unicamp.ic.mc302.veiculos;

public class Caminhao extends VeiculoRodoviario {
	private int capacidade;
	private int numDeEixos;
	
	public Caminhao(int cap, int num, int ano, String mar, String mod, String pl) {
		super(ano, mar, mod, pl);
		capacidade = cap;
		numDeEixos = num;
	}

	public void mostra() {
		System.out.println("\nTipo--->Caminhao");
		System.out.println("Capacidade = " + capacidade);
		System.out.println("Numero de Eixos = " + numDeEixos);
		super.mostra();
	}
	
	public boolean ligar(){
		System.out.println("Caminhao ligado!");
		return true;
	}
	
	public String toString(){
		mostra();
		return "";
	}
}