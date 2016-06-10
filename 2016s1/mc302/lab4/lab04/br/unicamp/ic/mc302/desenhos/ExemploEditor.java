package br.unicamp.ic.mc302.desenhos;

public class ExemploEditor {

	public static void main(String args[]) {
		
		Editor meuEditor = new Editor();
		
		// Adiciona Poligono
		double v[][] = {{0,0},{1,1},{2,2}};
		meuEditor.novoPoligono(3, v);
		
		// Adiciona Reta
		meuEditor.novaLinha(-1,-1,-2,-2);
		
		// Adiciona Circulo
		meuEditor.novoCirculo(1,5,5);
				
		// Adiciona grupo com duas figuras 
		meuEditor.novoGrupo();
		meuEditor.adicionaCirculo(3, -5, -5);
		meuEditor.adicionaLinha(-2, -8,-2,-8);
		
		// Imprime a tela
		meuEditor.exibeTela();
	}

}
