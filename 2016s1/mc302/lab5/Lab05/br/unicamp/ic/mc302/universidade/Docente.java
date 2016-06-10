package br.unicamp.ic.mc302.universidade;

import java.util.ArrayList;

public class Docente extends Pessoa {

	private ArrayList<String> disciplinas;
	private int anosDeTrabalho;
	
	public Docente(String nome){
		super(nome);
		disciplinas = new ArrayList<String>();
	}
	
	public void atribuiDisciplina(String codigo){
		disciplinas.add(codigo);
	}
	
	public void completaAno(){
		anosDeTrabalho++;
	}
	
	public int tempoAposentadoria(){
		return 30-anosDeTrabalho;
	}
	
	public void imprimeDisciplinas(){
		System.out.print("Leciona: ");
		for(String c: disciplinas){
			System.out.print(c + " ");
		}
		System.out.println("");
	}
	
	public void imprimeInfo(){
		super.imprimeInfo();
		imprimeDisciplinas();
	}	
}