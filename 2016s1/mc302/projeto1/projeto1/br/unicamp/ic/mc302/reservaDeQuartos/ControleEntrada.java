package br.unicamp.ic.mc302.reservaDeQuartos;

import java.util.Scanner;

import br.unicamp.ic.mc302.dadosPessoais.*;
import br.unicamp.ic.mc302.dataHora.DataHora;
import br.unicamp.ic.mc302.dataHora.Periodo;

public class ControleEntrada {

	private SistemaReservas sistema;
	private ControleReservas reservas;
	private ControleQuartos quartos;
	private ControleHospedes hospedes;
	private ControleOcupacao ocupacoes;
	private ControleFuncionarios funcionarios;
	private ControleLogin login;

	
	private ControleSaida out;
	
	Scanner in;
	
	public ControleEntrada(SistemaReservas sistema, ControleReservas reservas, ControleQuartos quartos, ControleHospedes hospedes,
			ControleFuncionarios funcionarios, ControleOcupacao ocupacoes, ControleLogin login, ControleSaida out) {	
		
		this.reservas = reservas;
		this.quartos = quartos;
		this.hospedes = hospedes;
		this.funcionarios = funcionarios;
		this.ocupacoes = ocupacoes;
		this.login = login;
		this.out = out;
		this.sistema = sistema;
		
		in = new Scanner(System.in);
	}
	
	private int getInt(String campo){
		out.println(campo);
		return in.nextInt();
	}
	
	private String getString(String campo){
		out.println(campo);
		return in.next();
	}
	
	private double getDouble(String campo){
		out.println(campo);
		return in.nextDouble();
	}
	
	public void inicio(){
		
		out.println("INICIO\n");
		int op = getInt("1. Login\n2. Sair\n");
		
		while(true){
			if(op==1)
				login();
			if(op==2)
				return;
		}
	}
	
	public void login(){
		
		out.println("LOGIN");
		
		if(login.login(getString("Nome:"), getString("Senha:"))){
			menuPrincipal();
		}
		else{
			out.println("Login/senha incorretos\n");
		}
	}
	
	public void menuPrincipal(){

		while(true){
			
			out.menuPrincipal();
			int op = in.nextInt();

			switch(op){
				case 1: 
					menuReservas();
					break;
				case 2:
					menuCheckin();
					break;
				case 3: 
					menuQuartos();
					break;
				case 4:	
					menuHospedes();
					break;
				case 5:	
					menuFuncionarios();
					break;
				case 9: 
					DataHora h = new DataHora(
							getInt("dia:"),
							getInt("mes:"),
							getInt("ano:"),
							getInt("hora:"),
							getInt("minuto:")
					);
					sistema.alterarHora(h);
					break;
				case 0: 
					login.logout();
					return;
			}
		}
	}

	public void menuReservas(){

		while(true){
						
			out.menuReservas();
			int op = in.nextInt();
		
			switch(op){
				case 1:
					out.println(reservas.listaReservas());
					break;
				case 2: 
					menuReserva(reservas.buscaReserva(getInt("Numero da reserva:")));
					break;
				case 3:
					novaReserva();
					break;
				case 0:
					return;
			}
		}
	}
	
	public void menuCheckin(){
		
		while(true){
			
			out.menuCheckin();
			int op = in.nextInt();
		
			switch(op){
				case 1:
					out.println(ocupacoes.listaOcupacoes());
					break;
				case 2:
					ocupacoes.ocupar(reservas.buscaReserva(getInt("Numero da reserva:")));
					break;
				case 3: 
					ocupacoes.desocupar(quartos.buscaQuarto(getInt("Numero do Quarto:")));
					break;
				case 0:
					return;
			}
		}
	}
	
	
	public void menuQuartos(){

		while(true){
			out.menuQuartos();
			int op = in.nextInt();
			
			switch(op){
				case 1: 
					out.println(quartos.listaQuartos());
					menuQuartos();
					break;
				case 2: 
					menuQuarto(quartos.buscaQuarto(getInt("Numero do quarto:")));
					break;
				case 3:	
					novoQuarto();
					menuQuartos();
					break;
				case 0:	
					menuPrincipal();
					break;
			}
		}
	}

	public void menuHospedes(){

		while(true){
			out.menuHospedes();
			int op = in.nextInt();
			
			switch(op){
				case 1: 
					out.println(hospedes.listaHospedes());
					menuHospedes();
					break;
				case 2: 
					menuHospede(hospedes.buscaHospede(getString("Nome do Hospede:")));
					break;
				case 3:	
					novoHospede();
					menuHospedes();
					break;
				case 0:	
					menuPrincipal();
					break;
			}
		}
	}
	
	public void menuFuncionarios(){

		while(true){
			out.menuFuncionarios();
			int op = in.nextInt();
			
			switch(op){
				case 1: 
					out.println(funcionarios.listaFuncionarios());
					break;
				case 2: 
					menuFuncionario(funcionarios.buscaFuncionario(getString("Nome do Funcionario:")));
					break;
				case 3:	
					novoFuncionario();
					break;
				case 0:	
					return;
		}
	}
}

	public void menuReserva(Reserva r){
	
		while(true){
			out.menuReserva(r);
			int op = in.nextInt();
			
			switch(op){
				case 1: 
					r.confirmar();
					return;
				case 2: 
					editarReserva(r);
					return;
				case 3:	
					reservas.removerReserva(r);
					return;		
				case 0:	
					return;
			}
		}
	}
	
	public void menuQuarto(Quarto q){
		
		while(true){
			out.menuQuarto(q);
			int op = in.nextInt();
			
			switch(op){
				case 1: 
					editarQuarto(q);
					return;
				case 2: 
					quartos.removerQuarto(q);
					return;
				case 0:	
					return;
			}
		}
	}
	
	public void menuHospede(Hospede h){
	
		while(true){
			out.menuHospede(h);
			int op = in.nextInt();
			
			switch(op){
				case 1: 
					editarHospede(h);
					return;
				case 2: 
					hospedes.removerHospede(h);
					return;
				case 0:	
					return;
			}	
		}
	}
	
	public void menuFuncionario(Funcionario f){
	
		while(true){
			out.menuFuncionario(f);
			int op = in.nextInt();
			
			switch(op){
				case 1: 
					editarFuncionario(f);
					return;
				case 2: 
					funcionarios.removerFuncionario(f);
					return;
				case 0:	
					return;
			}	
		}
	}
	
	public void editarReserva(Reserva r){
		
		int n = getInt("Alterar estadia? 1.Sim  2.Nao");
		
		if(n == 1){
			
			Periodo p = new Periodo(
					getInt("Chegada\ndia:"),
					getInt("mes:"),
					getInt("ano:"),
					getInt("hora:"),
					getInt("minuto:"),
					getInt("Saida\ndia:"),
					getInt("mes:"),
					getInt("ano:"),
					getInt("hora:"),
					getInt("minuto:")
			);
		
			reservas.editarReserva(r,p);
		}
		
		n = getInt("Alterar tipo do quarto? 1.Sim  2.Nao");
		
		if(n == 1){
			
			int tipo = getInt("tipo: "+QuartoSolteiro.id+".Solteiro "+QuartoCasal.id+".Casal "+QuartoSuiteLuxo.id+".Luxo");
			reservas.editarReserva(r,tipo);
		}
		
		
	}
	
	public void editarQuarto(Quarto q){
		
		quartos.removerQuarto(q);
		novoQuarto();
	}
	
	public void editarHospede(Hospede h){
		
		hospedes.removerHospede(h);
		novoHospede();
	}
	
	public void editarFuncionario(Funcionario f){
	
		funcionarios.removerFuncionario(f);
		novoFuncionario();
	}
	
	public void novaReserva(){
	
		int n = getInt("Cadastrar novo hospede? 1.Sim  2.Nao");
		
		if(n == 1)
			novoHospede();
		
		Reserva r = new Reserva(
				reservas.novoNumeroReserva(),
				getInt("tipo: "+QuartoSolteiro.id+".Solteiro "+QuartoCasal.id+".Casal "+QuartoSuiteLuxo.id+".Luxo"),
				hospedes.buscaHospede(getString("nome do hospede: ")),
				new Periodo(
						getInt("Chegada\ndia:"),
						getInt("mes:"),
						getInt("ano:"),
						getInt("hora:"),
						getInt("minuto:"),
						getInt("Saida\ndia:"),
						getInt("mes:"),
						getInt("ano:"),
						getInt("hora:"),
						getInt("minuto:")
				),
				getDouble("multa de cancelamento: "),
				getInt("forma de pagamento:"+Reserva.dinheiro+".Dinheiro "+Reserva.cartao+".Cartao "+Reserva.cheque+".Cheque"),
				getDouble("desconto: ")
		);
		
		reservas.novaReserva(r);
		out.println("Código da reserva: "+r.id()+"\n");
	}
	
	public void novoQuarto(){
		
		int tipo = getInt("tipo: "+QuartoSolteiro.id+".Solteiro "+QuartoCasal.id+".Casal "+QuartoSuiteLuxo.id+".Luxo");
		
		Quarto q = null;
		
		if(tipo == QuartoSolteiro.id){
			q = new QuartoSolteiro(
					getInt("codigo:"),
					getDouble("Preco:"),
					getInt("capacidade:"),
					getString("descricao:")
			);
		}
		
		else if(tipo == QuartoCasal.id){
			q = new QuartoCasal(
					getInt("codigo:"),
					getDouble("Preco:"),
					getInt("capacidade:"),
					getString("descricao:")
			);
		}

		else if(tipo == QuartoSuiteLuxo.id){
			q = new QuartoSuiteLuxo(
					getInt("codigo:"),
					getDouble("Preco:"),
					getInt("capacidade:"),
					getString("descricao:")
			);
		}
		
		if(q!= null)
			quartos.novoQuarto(q);
	}
	
	public void novoHospede(){
		
		Hospede h = new Hospede(
				getString("nome:"),
				new Documento(
						getString("documento"),
						getInt("tipo: "+Documento.RG+".RG "+Documento.CPF+".CPF "+Documento.passaporte+".passaporte")
				),
				new Endereco(
						getString("rua/avenida:"),
						getInt("numero:"),
						getString("complemento:"),
						getString("bairro:"),
						getString("cidade:"),
						getString("UF:"),
						getString("pais:")
				),
				getString("nacionalidade:"),
				getString("email:"),
				getString("telefone:")
		);
		
		hospedes.novoHospede(h);
	}
	
	public void novoFuncionario(){
		
		Funcionario f = new Funcionario(
				getString("nome:"),
				new Documento(
						getString("documento"),
						getInt("tipo: "+Documento.RG+".RG "+Documento.CPF+".CPF "+Documento.passaporte+".passaporte")
				),
				new Endereco(
						getString("rua/avenida:"),
						getInt("numero:"),
						getString("complemento:"),
						getString("bairro:"),
						getString("cidade:"),
						getString("UF:"),
						getString("pais:")
				),
				getString("telefone:"),
				getString("senha:")
		);
		
		funcionarios.novoFuncionario(f);
	}
	
}
