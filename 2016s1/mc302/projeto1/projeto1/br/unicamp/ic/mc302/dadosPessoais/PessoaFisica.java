package br.unicamp.ic.mc302.dadosPessoais;

public abstract class PessoaFisica {

	private String nome;
	private Documento documento;
	private Endereco endereço;
	private String telefone;
	
	public PessoaFisica() {
	}
	
	public PessoaFisica(String nome, Documento documento, Endereco endereco, String telefone){
		
		this.nome = nome;
		this.documento = documento;
		this.endereço = endereco;
		this.telefone = telefone;
	}

	public String nome(){
		return this.nome;
	}
	
	public Documento documento(){
		return this.documento;
	}
	
	public Endereco endereco(){
		return this.endereço;
	}
	
	public String telefone(){
		return this.telefone;
	}

	public void setNome(String nome){
		this.nome = nome;
	}
	
	public void setDocumento(Documento documento){
		this.documento = documento;
	}
	
	public void setEndereco(Endereco endereco){
		this.endereço = endereco;
	}
	
	public void setTelefone(String telefone){
		this.telefone = telefone;
	}
	
	
}
