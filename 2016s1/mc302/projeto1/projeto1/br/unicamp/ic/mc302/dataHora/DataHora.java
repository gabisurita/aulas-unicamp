package br.unicamp.ic.mc302.dataHora;

public class DataHora {

	Data data;
	Hora hora;
	public static DataHora agora;
	
	public DataHora(int dia, int mes, int ano, int hora, int minuto) {
		
		this.data = new Data(dia, mes, ano);
		this.hora = new Hora(hora, minuto);
	}

	public Data data(){
		return data;
	}
	
	public Hora hora(){
		return hora;
	}
	
	public int diferenca(DataHora h){
		return 1440*data.diferenca(h.data())+hora.diferenca(h.hora());
	}
	
	public boolean antes(DataHora h){
		return diferenca(h) < 0;
	}
	
	public boolean depois(DataHora h){
		return diferenca(h) > 0;
	}
	
	public String toString(){
		return data + " " + hora;
	}
	

	
}
