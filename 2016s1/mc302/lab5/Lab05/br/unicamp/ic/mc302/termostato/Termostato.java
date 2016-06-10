package br.unicamp.ic.mc302.termostato;

public class Termostato extends Termometro {
	//private Termometro termometro;
	private Chave chave;
	private float tempRequerida;
	
	public Termostato(){
		super();
		//termometro = new Termometro();
		chave = new Chave(); 
	}
	
	public void setTempRequerida(float temp){
		tempRequerida = temp; 
	}
	
	public void fazerMonitoramento(){
		//if (termometro.getTemperatura()>tempRequerida)
		if (getTemperatura()>tempRequerida)
			chave.desligar();
		else
			chave.ligar(); 
	}
	
	public boolean chaveLigada() {
		return chave.ligada();
	}
}
