package br.unicamp.ic.mc302.figuras;

abstract class Figura {

	void mover(int x, int y) {
		esconder();
		mostrar(x, y);
	}

	void esconder(){
		System.out.println("esconder da classe figura");
	}

	void mostrar(int x, int y){
		System.out.println("mostrar da classe figura");
	}
	
}
