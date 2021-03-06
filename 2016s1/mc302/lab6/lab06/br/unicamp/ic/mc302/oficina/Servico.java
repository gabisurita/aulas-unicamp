package br.unicamp.ic.mc302.oficina;

public class Servico {

	private String cliente;
	private String nome;
	private double preco;
	
	public Servico(String cliente, String nome, double preco) {
		this.cliente = cliente;
		this.nome = nome;
		this.preco = preco;
	}
	
	public Servico(double preco) {
		this("", "", preco);
	}
	
	public double preco(){
		return this.preco;
	}
	
	public String nome(){
		return this.nome;
	}
	
	public String cliente(){
		return this.cliente;
	}
}
