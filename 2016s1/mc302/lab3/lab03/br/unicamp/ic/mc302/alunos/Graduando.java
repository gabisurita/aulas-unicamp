package br.unicamp.ic.mc302.alunos;

public class Graduando extends EstudanteUniversitario {

	private float cr;
	private float cp;
	private float somaNotas;
	
	
	public Graduando(String nome, String cpf, String rg, String nomeDaMae, String nomeDoPai, String ra, String curso) {
		super(nome, cpf, rg, nomeDaMae, nomeDoPai, ra, curso);
		// TODO Auto-generated constructor stub
	}
	
	public void adicionaNota(float nota, int creditos){
		
		adicionaCreditos(creditos);
		
		somaNotas += nota*creditos;
		cr = somaNotas/getCreditos();
			
	}
	
	public float getCr(){return cr;}

}
