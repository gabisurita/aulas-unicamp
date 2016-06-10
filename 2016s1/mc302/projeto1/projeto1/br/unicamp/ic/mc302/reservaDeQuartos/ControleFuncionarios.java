package br.unicamp.ic.mc302.reservaDeQuartos;

import java.util.HashMap;

public class ControleFuncionarios {

	private HashMap<String,Funcionario> funcionarios;
		
	
	public ControleFuncionarios() {
		funcionarios = new HashMap<String,Funcionario>();
	}
	
	public Funcionario buscaFuncionario(String nome){
		return funcionarios.get(nome);
	}
	
	
	public String listaFuncionarios(){
		return funcionarios.toString();
	}
	
	public void novoFuncionario(Funcionario f){
		funcionarios.put(f.nome(), f);
	}
		
	public void removerFuncionario(Funcionario f){
		funcionarios.remove(f.nome());
	}



}
