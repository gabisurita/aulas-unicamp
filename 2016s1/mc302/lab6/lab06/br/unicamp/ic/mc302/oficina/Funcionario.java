package br.unicamp.ic.mc302.oficina;
import java.util.ArrayList;

public class Funcionario {

	private String nome;
	private ArrayList<Servico> servicos;
	private double salario;
	
	public Funcionario(String nome, double salario) {
		this.nome = nome;	
		this.salario = salario;
		servicos = new ArrayList<Servico>();
	}
	
	public String nome(){
		return nome;
	}
	
	public double salario(){
		return salario;
	}
	
	public int nServicos(String tipo){
		int sum = 0;
		
		for(Servico s: servicos){
			if(s.nome() == tipo)
				sum++;
		}
		
		return sum;
	}
	
	public double comissao(){
		
		double sum = 0;

		for(Servico s: servicos)
			sum += s.preco();
		
		return sum*0.10;
	}
	
	public boolean ehGerente(){
		return this instanceof Gerente;
	}
	
	public void adicionaServico(Servico s){
		servicos.add(s);
	}
}