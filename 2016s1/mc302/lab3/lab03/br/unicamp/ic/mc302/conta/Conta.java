package br.unicamp.ic.mc302.conta;

public class Conta {
    private double saldo; 
    public Conta (double sal) {saldo = sal;}
    public void credita(double valor) {saldo+= valor;}
    public void retira(double valor) {saldo-= valor;}
    public double getSaldo ( ) {return saldo;}
    public void setSaldo(double valor) {saldo = valor;}
}
