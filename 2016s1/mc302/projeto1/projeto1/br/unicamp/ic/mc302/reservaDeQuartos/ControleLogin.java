package br.unicamp.ic.mc302.reservaDeQuartos;

public class ControleLogin {

	private boolean autenticado = false;
	private ControleFuncionarios funcionarios;
	
	public ControleLogin(ControleFuncionarios func){
		this.funcionarios = func;
	}
	
	public boolean login(String nome, String senha){
		
		Funcionario f = funcionarios.buscaFuncionario(nome);
			
		if(f == null)
			return false;		

		autenticado = f.checarSenha(senha);
		return autenticado;
	}
	
	public void logout(){
		autenticado = false;
	}
}
