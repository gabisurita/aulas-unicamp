package br.unicamp.ic.mc302.veiculos;

public class ExemploCaminhao {
    
	public static void main(String args[]) {
		
		Caminhao caminhaozinho = new Caminhao(3, 5000);
		Caminhao caminhaozao = new Caminhao(6, 20000);
		
		System.out.println(caminhaozinho.numeroDeEixos());
		System.out.println(caminhaozinho.capacidadeMaxima());
		
		System.out.println(caminhaozao.numeroDeEixos());
		System.out.println(caminhaozao.capacidadeMaxima());
		
		
    }
}
