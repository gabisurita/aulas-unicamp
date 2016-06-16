package br.unicamp.ic.mc302.telefone;

public class ExemploFone {
	
    public static void main(String[] args) {
    	
        Telefone fone = new Telefone();
        Pessoa fulano = new Pessoa();
        SecretariaEletronica se = new SecretariaEletronica();
        EscutaClandestina es = new EscutaClandestina();

        fone.addTelefoneListener(se);
        fone.addTelefoneListener(es);
        fulano.escutaTelefone(fone);

        fone.tocaFone("12345678", "14/06/2016", "16h10");
        
    }
}
