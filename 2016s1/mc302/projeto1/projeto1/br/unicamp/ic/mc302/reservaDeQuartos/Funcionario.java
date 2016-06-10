package br.unicamp.ic.mc302.reservaDeQuartos;

import br.unicamp.ic.mc302.dadosPessoais.Documento;
import br.unicamp.ic.mc302.dadosPessoais.Endereco;
import br.unicamp.ic.mc302.dadosPessoais.PessoaFisica;

public class Funcionario extends PessoaFisica {

	private String senha;
	
	public Funcionario() {
	}

	public Funcionario(String nome, Documento documento, Endereco endereco, String telefone, String senha) {
		super(nome, documento, endereco, telefone);
		
		this.senha = senha;
	}
	
	public boolean setSenha(String senha, String novaSenha){
		
		if(checarSenha(senha)){
			this.senha = novaSenha;
			return true;
		}
		else{
			return false;
		}	
	}

	public boolean checarSenha(String senha){
		return this.senha.contentEquals(senha);
	}
	
	public String toString(){
		return ""
				+ "\nNome: "+nome()
				+ "\nDocumento: "+documento()
				+ "\nEndereco: "+endereco()
				+ "\nTelefone: "+telefone()
				+ "\n";
	}
}

