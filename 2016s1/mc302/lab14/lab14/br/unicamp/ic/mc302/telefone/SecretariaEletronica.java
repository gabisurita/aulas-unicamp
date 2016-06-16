package br.unicamp.ic.mc302.telefone;

public class SecretariaEletronica implements TelefoneListener {

	public void telefoneTocou(TelefoneEvent e) {
		System.out.println("Secretaria escuta o telefone n."+e.numero()+" tocando às "+e.hora()+" de "+e.data()+".");
	}

	public void telefoneAtendido(TelefoneEvent e) {
		System.out.println("Secretaria sabe que o telefone foi atendido.");
	}

}
