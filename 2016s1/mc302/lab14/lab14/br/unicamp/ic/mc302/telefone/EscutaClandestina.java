package br.unicamp.ic.mc302.telefone;

public class EscutaClandestina extends TelefoneAdapter {

	public EscutaClandestina() {
	}

	public void telefoneAtendido(TelefoneEvent e) {
		System.out.println("Escuta começa gravar conversa!");
	}

}
