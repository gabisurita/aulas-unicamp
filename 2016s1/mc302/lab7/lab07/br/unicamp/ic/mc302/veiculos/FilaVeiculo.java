package br.unicamp.ic.mc302.veiculos;

public class FilaVeiculo {
	private Veiculo veiculos[];
	private boolean vazia = true;
	private int ultimaPosicao = 0;

	public FilaVeiculo() {
		veiculos = new Veiculo[50];
	}

	public boolean Vazia() {
		return vazia;
	}

	public void adicionaVeiculo(Veiculo item) {
		if (ultimaPosicao <= 50) {
			if (item != null) {
				veiculos[ultimaPosicao] = item;
			} else {
				System.out.println("A Fila s� pode conter ve�culos v�lidos\n");
			}
		} else {
			System.out.println("O veiculo n�o poder� ser adicionado, pois a fila est� cheia");
		}
		ultimaPosicao++;
		vazia = false;
	}

	public void mostraFila() {
		for (int i = 0; i < ultimaPosicao; i++) {
			veiculos[i].mostra();
		}
	}
	
	public void ligarTodos() {
		for (int i = 0; i < ultimaPosicao; i++) 
			veiculos[i].ligar();
	}

}
