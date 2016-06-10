package br.unicamp.ic.mc302.dadosPessoais;

public class Endereco {

	private String logradouro;
	private int numero;
	private String complemento;
	private String bairro;
	private String cidade;
	private String uf;
	private String pais;
	private String cep;
	
	public Endereco() {
	}
	
	public Endereco(String logradouro, int numero, String complemento, 
			String bairro, String cidade, String uf, String cep) {
		
		this.atualizar(logradouro, numero, complemento, bairro, cidade, uf, pais, cep);
	}
	
	public void atualizar(String logradouro, int numero, String complemento, 
			String bairro, String cidade, String uf, String pais, String cep){

		this.logradouro = logradouro;
		this.numero = numero;
		this.complemento = complemento;
		this.bairro = bairro;
		this.cidade = cidade;
		this.uf = uf;		
		this.pais = pais;
		this.cep = cep;
	}

	public String toString(){
		
		return "Endereço: "+logradouro +", "+numero+", "+numero+", "+complemento+", "
				+bairro+", "+cidade+", "+uf+", CEP "+cep;
	}
	
	
}
