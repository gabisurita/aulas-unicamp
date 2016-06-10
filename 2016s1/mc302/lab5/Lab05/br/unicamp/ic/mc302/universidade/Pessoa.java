package br.unicamp.ic.mc302.universidade;

public class Pessoa {

	private String nome;
	private String rg;
	private String cpf;
	private String mae;
	private String pai;
	
	public Pessoa(String nome) {
		this.nome = nome;
	}
	
	public void insereDocumentos(String rg, String cpf){
		this.rg = rg;
		this.cpf = cpf;
	}
	
	public void insereParentes(String mae, String pai){
		this.mae = mae;
		this.pai = pai;
	}
	
	public void imprimeInfo(){
		System.out.println("Nome: "+nome);
		System.out.println("RG: "+rg);
		System.out.println("CPF: "+cpf);
		System.out.println("Nome da Mae: "+mae);
		System.out.println("Nome do Pai: "+pai);
	}

}
