package br.unicamp.ic.mc302.oficina;

public class Gerente extends Funcionario {

	public Gerente(String nome, double salario) {
		super(nome, salario);
	}
	
	public double comissao(){
		return super.comissao()*10*0.15;
	}
	
}
