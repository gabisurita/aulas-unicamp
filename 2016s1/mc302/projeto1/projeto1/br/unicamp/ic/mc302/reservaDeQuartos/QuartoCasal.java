package br.unicamp.ic.mc302.reservaDeQuartos;
public class QuartoCasal extends Quarto {
	
	public static int id = 2; 
	
	public QuartoCasal(int codigo, double preco, int capacidade, String descricao) {
		super(codigo, preco, capacidade, descricao);
		this.setId(id);
	}

	public String toString(){	
		return super.toString() + "Tipo: Casal\n"; 
	}
}
