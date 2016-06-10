package br.unicamp.ic.mc302.desenhos;

import java.util.ArrayList;

public class Tela {

	private ArrayList<Figura> figuras;
	private int nFiguras;
	private ArrayList<Grupo> corrente;
	
	public Tela(){
		figuras = new ArrayList<Figura>();
		corrente = new ArrayList<Grupo>();
		nFiguras = 0;
	}

	public void novoPoligono(int l, double v[][]){
		
		Figura fig = new Poligono(this, l, v);
		figuras.add(fig);
		nFiguras++;
	}
	
	public void novaLinha(double xi, double yi, double xf, double yf){
		
		Figura fig = new Linha(this, xi, yi, xf, yf);
		figuras.add(fig);
		nFiguras++;
	}
	
	public void novoCirculo(double r, double cx, double cy){
		
		Figura fig = new Circulo(this, r, cx, cy);
		figuras.add(fig);
		nFiguras++;
	}
	
	public void novoGrupo(){
		
		Grupo g = new Grupo(this);
		figuras.add(g);
		nFiguras++;
		corrente.add(g);
	}
	
	public void adicionaPoligono(int l, double v[][]){
		
		Figura fig = new Poligono(this, l, v);
		corrente.get(corrente.size()-1).adicionaFigura(fig);
		
	}
	
	public void adicionaLinha(double xi, double yi, double xf, double yf){
		
		Figura fig = new Linha(this, xi, yi, xf, yf);
		corrente.get(corrente.size()-1).adicionaFigura(fig);
	}
	
	public void adicionaCirculo(double r, double cx, double cy){
		
		Figura fig = new Circulo(this, r, cx, cy);
		corrente.get(corrente.size()-1).adicionaFigura(fig);
	}
	
	public void fechaGrupo(){
		corrente.remove(corrente.size()-1);
	}
	
	
	public void desenhar(){
		System.out.println("Desenha a tela");
		
		for(Figura f : figuras){
			f.desenhar();
		}
	}
}
