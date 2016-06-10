package br.unicamp.ic.mc302.reservaDeQuartos;

public abstract class Quarto {

	private int codigo;
	private double preco;
	private int capacidade;
	private String descricao;
	private int id;
	
	public Quarto(){
	}
	
	public Quarto(int codigo, double preco, int capacidade, String descricao) {

		this.codigo = codigo;
		this.preco = preco;
		this.capacidade = capacidade;
		this.descricao = descricao;
	}
	
	public int codigo(){
		return this.codigo;
	}
	
	public double preco(){
		return this.preco;
	}
	
	public int capacidade(){
		return this.capacidade;
	}
	
	public String descricao(){
		return this.descricao;
	}
	
	public String toString(){
		
		String s = "";	
		s += "\nCodigo: "+codigo();
		s += "\nPreco: "+preco;
		s += "\nCapacidade: "+capacidade+" pessoas";
		s += "\nDescriçao "+descricao;
		s += "\n";
		
		return s;
	}
	
	public int id(){
		return id;
	}
	
	protected void setId(int id){
		this.id = id;
	}
}
