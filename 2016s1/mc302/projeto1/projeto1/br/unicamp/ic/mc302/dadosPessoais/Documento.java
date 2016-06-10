package br.unicamp.ic.mc302.dadosPessoais;

public class Documento {

	public static int RG = 1;
	public static int CPF = 2;
	public static int passaporte = 3;
	
	private String numero;
	private int tipo;
	
	public Documento() {
	}
	
	public Documento(String numero, int tipo) {
		this.numero = numero;
		this.tipo = tipo;
	}
	
	public String numero(){
		return numero;
	}
	
	public int tipo(){
		return tipo;
	}
	
	public String toString(){
		String s = "";
		if (tipo == RG)
			s += "RG: ";
		else if (tipo == CPF)
			s += "CPF: ";
		else if (tipo == passaporte)
			s += "Passaporte: ";
		
		s += numero;
		return s;
	}
	
}
