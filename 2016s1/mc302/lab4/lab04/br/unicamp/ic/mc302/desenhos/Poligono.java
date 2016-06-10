package br.unicamp.ic.mc302.desenhos;

public class Poligono extends Figura {

	private int lados;
	private Linha linhas[];
	
	public Poligono(Tela tela, int l, double v[][]) {
		
		super(tela);
		
		lados = l;
		linhas = new Linha[l];
		
		for(int i=0; i<l-1; i++){
			linhas[i] = new Linha(tela, v[i][0], v[i][1], v[i+1][0], v[i+1][1]);
		}
		
		linhas[l-1] = new Linha(tela, v[l-1][0], v[l-1][1], v[0][0], v[0][1]);
	}

	public void desenhar(){
		System.out.println("Imprime poligono de "+lados+" lados");
		
		for(Linha l : linhas){
			l.desenhar();
		}
	}
}
