package br.unicamp.ic.mc302.contaCor;

public class ExemploCoercao {

	public static void main(String args[]) {
		int saldoInicialChico = 100;
		byte numeroChico = 30;
		byte senhaChico = 99;

		int saldoInicialBelchior = 200;
		byte numeroBelchior = 31;
		byte senhaBelchior = 91;

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
