package br.unicamp.ic.mc302.contaDePoup;

import br.unicamp.ic.mc302.conta.Conta;

class ContaDePoup extends Conta {
    private double indice; // indice de rendimento
    public ContaDePoup(double sal) { super(sal); }
    public double calcula( ){  // calcula e deposita o rendimento
        double i = indice*getSaldo(); 
        credita(i);
        return i;
    }
    public void retira(double v) { super.retira(v); }
    
} // fim da classe ContaDePoup

