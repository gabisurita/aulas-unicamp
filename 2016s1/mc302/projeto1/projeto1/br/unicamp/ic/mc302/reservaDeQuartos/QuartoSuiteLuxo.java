package br.unicamp.ic.mc302.reservaDeQuartos;

public class QuartoSuiteLuxo extends Quarto {
	
	public static int id = 3; 

	public QuartoSuiteLuxo(int codigo, double preco, int capacidade, String descricao) {
		super(codigo, preco, capacidade, descricao);
		this.setId(id);
	}
	
	public String toString(){	
		return super.toString() + "Tipo: Suite de Luxo\n"; 
	}
}
