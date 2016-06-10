package br.unicamp.ic.mc302.dataHora;

public class Periodo {

	DataHora inicio;
	DataHora fim;
	
	public Periodo(DataHora inicio, DataHora fim) {
		
		this.inicio = inicio;
		this.fim = fim;
	}
	
	public Periodo(int idia, int imes, int iano, int ihora, int iminuto, 
			int fdia, int fmes, int fano, int fhora, int fminuto) {

		inicio = new DataHora(idia, imes, iano, ihora, iminuto);
		fim = new DataHora(fdia, fmes, fano, fhora, fminuto);
	}

	public DataHora inicio(){
		return inicio;
	}
	
	public DataHora fim(){
		return fim;
	}
	
	public boolean cruza(Periodo p){
		if(fim.antes(p.inicio) || inicio.depois(p.fim))
			return false;
		else
			return true;
		
	}

	public boolean maior(Periodo p){
		int d = fim.diferenca(inicio);
		int dp = p.fim().diferenca(p.inicio());
		
		return dp > d;
	}
	
	public boolean menor(Periodo p){
		return !maior(p);
	}
}
