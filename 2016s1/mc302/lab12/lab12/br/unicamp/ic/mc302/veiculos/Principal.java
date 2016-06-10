package br.unicamp.ic.mc302.veiculos;

public class Principal {
	
	public static void main(String[] args) {
		
		Veiculo carroAnfibio = new Veiculo();
		
		carroAnfibio.ligar();
		carroAnfibio.andar();
		carroAnfibio.mudarEstado();
		carroAnfibio.andar();
		carroAnfibio.mudarEstado();
		carroAnfibio.andar();
	}
}
