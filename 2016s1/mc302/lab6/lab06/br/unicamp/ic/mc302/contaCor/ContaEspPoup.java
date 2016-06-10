package br.unicamp.ic.mc302.contaCor;

public class ContaEspPoup extends ContaEsp {

	public ContaEspPoup(String nome, double val, int num, int pwd) {
		super(nome, val, num, pwd);
	}
	
	public final boolean debitaValor(double val, int pwd) {
		super.debitaValor(val, pwd);
	}

}
