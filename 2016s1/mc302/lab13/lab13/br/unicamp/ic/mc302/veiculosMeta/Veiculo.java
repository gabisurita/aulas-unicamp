package br.unicamp.ic.mc302.veiculosMeta;

abstract class Veiculo {
//	private static int contadorVeiculos;
	private int placa;

	public Veiculo(int placa) {
		this.placa = placa;
//		contadorVeiculos++;
	}
//
//	public static int getContadorVeiculos() {
//		return contadorVeiculos;
//	}

	public void mostrar() { // imprime dados do ve�culo
		System.out.println("PLACA: " + placa);
	}
}
