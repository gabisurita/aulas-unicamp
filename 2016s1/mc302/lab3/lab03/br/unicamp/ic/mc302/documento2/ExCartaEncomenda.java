package br.unicamp.ic.mc302.documento2;

public class ExCartaEncomenda {

	public static void main(String[] args) {
		
		CartaRegistarada c = new CartaRegistarada("05032016", "Campinas");
		Encomenda e = new Encomenda("Compra");
		
		c.imprimir();
		e.imprimir();
	}

}
