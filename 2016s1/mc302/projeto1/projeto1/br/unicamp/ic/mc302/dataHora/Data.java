package br.unicamp.ic.mc302.dataHora;

public class Data {

	private int dia;
	private int mes;
	private int ano;
	
	public Data(int dia, int mes, int ano) {
		
		this.dia = dia;
		this.mes = mes;
		this.ano = ano;
	}

	public int dia(){
		return dia;
	}
	
	public int mes(){
		return mes;
	}
	
	public int ano(){
		return ano;
	}
	
	public int diferenca(Data d){
		return 365*ano+31*mes+dia-(365*d.ano+31*d.mes+d.dia);
	}
	
	public String toString(){
		return dia+"/"+mes+"/"+ano;
	}
	
}
