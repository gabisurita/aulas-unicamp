package br.unicamp.ic.mc302.desenhos;

public class Circulo extends Figura {

	private double r;
	private double cx;
	private double cy;
	
	
	public Circulo(Tela tela, double r, double cx, double cy){
		super(tela);
		
		this.r = r;
		this.cx = cx;
		this.cy = cy;
	}
	
	public void desenhar(){
		System.out.println("Imprime circulo: centro=("+cx+", "+cy+"); raio="+r);
	}
}