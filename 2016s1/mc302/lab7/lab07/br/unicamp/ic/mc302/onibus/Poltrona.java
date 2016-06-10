package br.unicamp.ic.mc302.onibus;

public abstract class Poltrona {

	private boolean ocupada;
	
	public Poltrona() {
		this.ocupada = false;
	}

	public boolean ocupar(){
		
		if(!this.ocupada){
		
			this.ocupada = true;
			return true;
		}
		else{
			return false;
		}
	}
	
	public boolean desocupar(){
		if(this.ocupada){
			
			this.ocupada = false;
			return true;
		}
		else{
			return false;
		}
	}
	
	public boolean ocupada(){
		return this.ocupada;
	}
	
	public abstract double preco();
}