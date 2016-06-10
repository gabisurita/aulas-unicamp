package br.unicamp.ic.mc302.alunos;

public class Pessoa {
	
	private String nome;
	private String cpf;
	private String rg;
	private String nomeDaMae;
	private String nomeDoPai;
	
	public Pessoa(String nome, String cpf, String rg, String nomeDaMae, String nomeDoPai){
		this.nome = nome;
		this.cpf = cpf;
		this.rg = rg;
		this.nomeDaMae = nomeDaMae;
		this.nomeDoPai = nomeDoPai;
	}
	
	public String getNome(){return nome;}
	public String getCpf(){return cpf;}
	public String getRg(){return rg;}
	
}
