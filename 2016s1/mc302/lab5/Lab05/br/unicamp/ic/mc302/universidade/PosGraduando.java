package br.unicamp.ic.mc302.universidade;

import java.util.ArrayList;

public class PosGraduando extends EstudanteUniveristario {
	
	private ArrayList<Character> notasPos;
	
	public PosGraduando(String nome, String ra) {
		super(nome, ra);
		notasPos = new ArrayList<Character>();
	}

	public void adicionaNota(Character nota){
		notasPos.add(nota);
	}
	
	public double converteNotas(){
		double sum = 0;
		
		for(Character n: notasPos){
			sum += 10 - 2*(double)(n.charValue()-'A');
		}
		
		return sum/notasPos.size();
	}
	
	public void imprimeInfo(){
		super.imprimeInfo();
		System.out.println("Nota: "+converteNotas());
	}
}
