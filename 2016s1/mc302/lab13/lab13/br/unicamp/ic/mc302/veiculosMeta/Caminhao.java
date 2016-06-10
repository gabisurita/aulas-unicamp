package br.unicamp.ic.mc302.veiculosMeta;

class Caminhao extends Veiculo {
//	private static int contadorCaminhoes;
	private int tipoDaCarga;

	public Caminhao(int placa, int tipoDaCarga) {
		super(placa);
		this.tipoDaCarga = tipoDaCarga;
//		contadorCaminhoes++;
	}
//
//	public static int getContadorCaminhoes() {
//		return contadorCaminhoes;
//	}

	public void mostrar() { // imprime dados do ve�culo
		System.out.println("Caminhao, para o TIPO DE CARGA: " + tipoDaCarga);
		super.mostrar();
	}
}
