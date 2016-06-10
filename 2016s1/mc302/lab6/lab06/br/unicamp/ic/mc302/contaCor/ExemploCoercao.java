package br.unicamp.ic.mc302.contaCor;

public class ExemploCoercao {

	public static void main(String args[]) {
		float saldoInicialChico = 100;
		float numeroChico = 30;
		float senhaChico = 99;

		float saldoInicialBelchior = 200;
		float numeroBelchior = 31;
		float senhaBelchior = 91;

		ContaCor cc1 = new ContaCor("Chico", saldoInicialChico, numeroChico,
				senhaChico); // Compilacao falha. esse construtor espera
								// (String, double, int, int). O compilardor
								// nao consegue achar um construtor que case
								// com (String, double, float, long).
								// Similarmente
								// para o caso abaixo.

		ContaCor cc2 = new ContaCor("Belchior", saldoInicialBelchior,
				numeroBelchior, senhaBelchior);
	}
}
