package br.unicamp.ic.mc302.conta;

import br.unicamp.ic.mc302.contaDePoup.ContaDePoup;

public class ExemploConta {

    public static void main(String args[]) {

    	ContaDePoup c1 = new ContaDePoup(100);
        c1.calcula( );

        ContaDePoup c2 = new ContaDePoup(100);

        c2.calcula( );
        c2.credita(10);
    }
}


