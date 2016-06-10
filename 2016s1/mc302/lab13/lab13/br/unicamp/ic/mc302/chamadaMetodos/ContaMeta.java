package br.unicamp.ic.mc302.chamadaMetodos;

public class ContaMeta {
	private float saldo;
	private int contadorNumMsgObjeto;
	static private int contadorNumMsgClasse;

	public ContaMeta() {
		saldo = 0;
		contadorNumMsgObjeto = 0;
	}

	public void creditar(float valor) {
		saldo += valor;
		System.out.println("O metodo foi executado;");
		// incrementar o contador de chamadas do objeto
		contadorNumMsgObjeto++;
		contadorNumMsgClasse++;
	}

	public void mostrarNumMsgObjeto() {
		System.out.println(contadorNumMsgObjeto+" mensagens.");
	}
	
	public static void mostrarNumMsgClasse() {
		System.out.println(contadorNumMsgClasse+" mensagens.");
	}
	
}
