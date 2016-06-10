package br.unicamp.ic.mc302.dataHora;

public class Hora {


	private int hora;
	private int minuto;
	 
	public Hora(int hora, int minuto) {
		
		this.hora = hora;
		this.minuto = minuto;
	}

	public int hora(){
		return hora;
	}
	
	public int minuto(){
		return minuto;
	}
	
	public int diferenca(Hora h){
		return 60*hora+minuto-(60*h.hora()+h.minuto());
	}
	
	public String toString(){
		return hora+":"+minuto;
	}
	
}
