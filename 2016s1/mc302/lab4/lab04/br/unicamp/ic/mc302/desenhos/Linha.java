package br.unicamp.ic.mc302.desenhos;

public class Linha extends Figura {

	private double xi;
	private double yi;
	private double xf;
	private double yf;
	
	
	public Linha(Tela tela, double xi, double yi, double xf, double yf) {
		
		super(tela);
		
		this.xi = xi;
		this.xf = xf;
		this.yi = yi;
		this.yf = yf;
	}
	
	public void desenhar(){
		System.out.println("Imprime linha: inicio=("+xi+" ,"+yi+"); fim=("+xf+" ,"+yf+")");
	}

}
