package br.unicamp.ic.mc302.veiculos;

public abstract class Veiculo {
	private String marca;
	private String modelo;
	private int anoModelo;

	public Veiculo(int ano, String mar, String mod) {
		marca = mar;
		modelo = mod;
		anoModelo = ano;
	}

	public void mostra() {
		System.out.println("Marca = " + marca);
		System.out.println("Modelo = " + modelo);
		System.out.println("Ano Modelo = " + anoModelo);
	}
	
	public abstract boolean ligar();

}