package br.unicamp.ic.mc302.reservaDeQuartos;

public class ControleSaida {
	
	public void println(String s){
		System.out.println(s);
	}

	public void menuPrincipal(){
		println(""
				+ "Menu Principal: \n\n"
				+ "1. Reservas\n"
				+ "2. Check-in\n"
				+ "3. Quartos\n"
				+ "4. Hospedes\n"
				+ "5. Funcionários\n"
				+ "\n"
				+ "9. Trocar hora do sistema\n"
				+ "0. Sair\n"
				);
	}

	public void menuReservas(){
		println(""
				+ "Menu de Reservas: \n\n"
				+ "1. Lista de Reservas\n"
				+ "2. Buscar Reserva\n"
				+ "3. Criar Reserva\n"
				+ "\n"
				+ "0. Voltar ao menu anterior\n"
				);
	}

	public void menuCheckin(){
		println(""
				+ "Menu de Check-in: \n\n"
				+ "1. Lista de Ocupacoes\n"
				+ "2. Check-in\n"
				+ "3. Check-out\n"
				+ "\n"
				+ "0. Voltar ao menu anterior\n"
				);
	}
	
	public void menuQuartos(){
		println(""
				+ "Menu de Quartos: \n\n"
				+ "1. Lista de Quartos\n"
				+ "2. Buscar Quarto\n"
				+ "3. Adicionar Quarto\n"
				+ "\n"
				+ "0. Voltar ao menu anterior\n"
				);
	}
	
	public void menuHospedes(){
		println(""
				+ "Menu de Hospedes: \n\n"
				+ "1. Lista de Hospedes\n"
				+ "2. Buscar Hospede\n"
				+ "3. Adicionar Hospede\n"
				+ "\n"
				+ "0. Voltar ao menu anterior\n"
				);
	}
	
	public void menuFuncionarios(){
		println(""
				+ "Menu de Funcionarios: \n\n"
				+ "1. Lista de Funcionarios\n"
				+ "2. Buscar funcionario\n"
				+ "3. Adicionar Funcionario\n"
				+ "\n"
				+ "0. Voltar ao menu anterior\n"
				);
	}
	
	
	public void menuReserva(Reserva r){
		println(""
				+ "Reserva: \n"
				+  r + "\n"
				+ "1. Confirmar\n"
				+ "2. Editar\n"
				+ "3. Cancelar\n"
				+ "\n"
				+ "0. Voltar ao menu anterior\n"
				);		
	}

	public void menuQuarto(Quarto q){
		println(""
				+ "Quarto: \n"
				+  q + "\n"
				+ "1. Editar\n"
				+ "2. Excluir\n"
				+ "\n"
				+ "0. Voltar ao menu anterior\n"
				);		
	}
	
	public void menuHospede(Hospede h){
		println(""
				+ "Hospede: \n"
				+  h + "\n"
				+ "1. Editar\n"
				+ "2. Excluir\n"
				+ "\n"
				+ "0. Voltar ao menu anterior\n"
				);		
	}
	
	public void menuFuncionario(Funcionario f){
		println(""
				+ "Hospede: \n"
				+  f + "\n"
				+ "1. Editar\n"
				+ "2. Excluir\n"
				+ "\n"
				+ "0. Voltar ao menu anterior\n"
				);		
	}
}
