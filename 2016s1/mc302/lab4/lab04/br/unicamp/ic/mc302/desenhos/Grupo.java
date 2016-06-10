package br.unicamp.ic.mc302.desenhos;

import java.util.ArrayList;

public class Grupo extends Figura {

	private ArrayList<Figura> figuras;
	
	public Grupo(Tela tela) {
		super(tela);
		figuras = new ArrayList<Figura>(); 
	}
	
	public void adicionaFigura(Figura fig){
		figuras.add(fig);
	}
	
	public void desenhar(){
		
		System.out.println("Imprime Grupo");
		
		for(Figura f : figuras){
			f.desenhar();
		}
	}
	
	

}
