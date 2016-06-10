package br.unicamp.ic.mc302.veiculos;

public class Inicial {

	public static void main(String[] args) {
		//FilaVeiculo fila;
		Fila<Veiculo> fila;
		
		//fila = new FilaVeiculo();
		fila = new Fila<Veiculo>();
		
		System.out.println("A Fila de Veiculos contem:");
		//fila.adicionaVeiculo(new Carro(5, 2, 1999, "VOLKSWAGEN", "GOL", "EST3245"));
		//fila.adicionaVeiculo(new Caminhao(15000, 3, 1997, "VOLKSWAGEN", "TITAN", "KED9871"));
		//fila.adicionaVeiculo(new Carro(5, 1, 1998, "FIAT", "PALIO", "JKU2171"));
		//fila.adicionaVeiculo(new Carro(5, 5, 2001, "FORD", "FIESTA", "JNM2464"));
		//fila.adicionaVeiculo(new Caminhao(10000, 2, 2000, "FORD", "CARGO", "KMG4171"));
		//fila.adicionaVeiculo(new Carro(4, 2, 2001, "CHEVROLET", "CELTA", "JGH5432"));
		//fila.adicionaVeiculo(new Caminhao(8000, 4, 1996, "FORD", "SCANIA", "DEY6429"));
		
		fila.adiciona(new Carro(5, 2, 1999, "VOLKSWAGEN", "GOL", "EST3245"));
		fila.adiciona(new Caminhao(15000, 3, 1997, "VOLKSWAGEN", "TITAN", "KED9871"));
		fila.adiciona(new Carro(5, 1, 1998, "FIAT", "PALIO", "JKU2171"));
		fila.adiciona(new Carro(5, 5, 2001, "FORD", "FIESTA", "JNM2464"));
		fila.adiciona(new Caminhao(10000, 2, 2000, "FORD", "CARGO", "KMG4171"));
		fila.adiciona(new Carro(4, 2, 2001, "CHEVROLET", "CELTA", "JGH5432"));
		fila.adiciona(new Caminhao(8000, 4, 1996, "FORD", "SCANIA", "DEY6429"));
		
		if (!fila.Vazia()) {
			fila.mostraFila();
		} else {
			System.out.println("Fila est� vazia");
		}
		
		//fila.ligarTodos();
	}
}// fim classe Inicial