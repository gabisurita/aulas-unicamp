package br.unicamp.ic.mc302.reservaDeQuartos;

import br.unicamp.ic.mc302.dadosPessoais.*;

public class Hospede extends PessoaFisica {

	public String nacionalidade;
	public String email;
	
	public Hospede() {
	}

	public Hospede(String nome, Documento documento, Endereco endereco, 
			String nacionalidade, String email, String telefone) {
		
		super(nome, documento, endereco, telefone);

		this.nacionalidade = nacionalidade;
		this.email = email;
	}

	public String nacionalidade(){
		return this.nacionalidade;
	}
	
	public String email(){
		return this.email;
	}
	
	public String toString(){
		return ""
				+ "\nNome: "+nome()
				+ "\nDocumento: "+documento()
				+ "\nEndereco: "+endereco()
				+ "\nNacionalidade: "+nacionalidade()
				+ "\nEmail: "+email()
				+ "\nTelefone: "+telefone()
				+ "\n";
	}
}
