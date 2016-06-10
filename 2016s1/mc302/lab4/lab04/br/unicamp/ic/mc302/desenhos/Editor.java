package br.unicamp.ic.mc302.desenhos;

public class Editor {
	
	private Tela tela;
	
	public Editor(){
		tela = new Tela();
	}
	
	public void novoPoligono(int l, double v[][]){
		tela.novoPoligono(l, v);
	}
	
	public void novaLinha(double xi, double yi, double xf, double yf){
		tela.novaLinha(xi, yi, xf, yf);
	}
	
	public void novoCirculo(double r, double cx, double cy){
		tela.novoCirculo(r, cx, cy);
	}
	
	public void novoGrupo(){
		tela.novoGrupo();
	}
	
	public void adicionaPoligono(int l, double v[][]){
		tela.adicionaPoligono(l, v);
	}
	
	public void adicionaLinha(double xi, double yi, double xf, double yf){
		tela.adicionaLinha(xi, yi, xf, yf);
	}
	
	public void adicionaCirculo(double r, double cx, double cy){
		tela.adicionaCirculo(r, cx, cy);
	}
	
	public void fechaGrupo(){
		tela.fechaGrupo();
	}
	
	public void exibeTela(){
		tela.desenhar();
	}
	
}
