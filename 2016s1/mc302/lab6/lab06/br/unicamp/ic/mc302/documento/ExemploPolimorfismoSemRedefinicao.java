package br.unicamp.ic.mc302.documento;

public class ExemploPolimorfismoSemRedefinicao {

	public static void main(String args[]) {
		Documento d = new Documento();
		d.imprimir();
		d = new Carta(); // d pode tambem referenciar um objeto do tipo Carta
		
		d.imprimir();
		
		if(d instanceof Carta){
			Carta c = (Carta)d;
			c.anexar(); 
		}
		
		d = new Telegrama(); // d pode tambem referenciar um objeto do tipo
		
		// Telegrama
		d.imprimir();
		
		if(d instanceof Telegrama){
			Telegrama t = (Telegrama)d;
			t.registrar(); 
			t.pagar(); 		
		}
	}
}