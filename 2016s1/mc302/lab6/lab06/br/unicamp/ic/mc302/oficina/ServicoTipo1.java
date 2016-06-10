package br.unicamp.ic.mc302.oficina;

public class ServicoTipo1 extends Servico {

	public ServicoTipo1(String cliente, String nome) {
		super(cliente, "Tipo1", 15);
	}

	public ServicoTipo1() {
		super("", "Tipo2", 50);
	}

}
