package br.unicamp.ic.mc302.termostato;

public class ExemploTermostato {

	public static void main(String[] args) {
		
		Termostato t = new Termostato();
		
		/* Produzem Erros! */
		//Chave t = new Termostato();
		//Termometro t = new Termostato(); 
		
		t.setTempRequerida(25);
		t.fazerMonitoramento();
		System.out.println("Ligado? "+ t.chaveLigada());
	}

}
