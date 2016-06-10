package br.unicamp.ic.mc302.onibus;

public class Poltrona {
	
	private boolean ocupada; 
	
	public Poltrona(){
	}
	
	public boolean estaOcupada(){
		return ocupada;
	}
	
	public void ocupar(){
		ocupada = true;
	}
	
	public void desocupar(){
		ocupada = false;
	}
}