package br.unicamp.ic.mc302.alunos;

public class EstudanteUniversitario extends Pessoa {

	private String ra;
	private String curso;
	private int creditosConcluidos;
	
	public EstudanteUniversitario(String nome, String cpf, String rg, String nomeDaMae, String nomeDoPai, 
			String ra, String curso){
	
		super(nome, cpf, rg, nomeDaMae, nomeDoPai);
		
		this.ra = ra;
		this.curso = curso;
		this.creditosConcluidos = 0;
	}
	
	public String getRa(){return ra;}
	
	protected void adicionaCreditos(int n){creditosConcluidos +=n;}
	public int getCreditos(){return creditosConcluidos;}
}
