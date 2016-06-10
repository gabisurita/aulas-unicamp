package br.unicamp.ic.mc302.universidade;

public class EstudanteUniveristario extends Pessoa {

	private String ra;
	private String curso;
	private int creditos;
	
	public EstudanteUniveristario(String nome, String ra) {
		super(nome);
		this.ra = ra;
	}
	
	public void defineCurso(String curso){
		this.curso = curso;
	}
	
	public void adicionaCreditos(int c){
		creditos += c;
	}

	public void imprimeInfo(){
		super.imprimeInfo();
		System.out.println("RA: "+ra);
		System.out.println("Curso: "+curso);
		System.out.println("Creditos concluidos: "+creditos);
	}
}
