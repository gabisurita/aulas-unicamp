package br.unicamp.ic.mc302.reservaDeQuartos;
public class QuartoSolteiro extends Quarto {	
	
	public static int id = 1; 

	public QuartoSolteiro(int codigo, double preco, int capacidade, String descricao) {
		super(codigo, preco, capacidade, descricao);
		this.setId(id);
	}

	public String toString(){
		return super.toString() + "Tipo: Solteiro\n"; 
	}
}
