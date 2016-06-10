package br.unicamp.ic.mc302.reservaDeQuartos;

import br.unicamp.ic.mc302.dataHora.DataHora;

public class SistemaReservas {

	private ControleReservas reservas;
	private ControleQuartos quartos;
	private ControleHospedes hospedes;
	private ControleFuncionarios funcionarios;
	private ControleOcupacao ocupacoes;
	private ControleLogin login;
	private ControleEntrada in;
	private ControleSaida out;
	
	private DataHora horaDoSistema;
	
	public SistemaReservas() {
		
		out = new ControleSaida();
		quartos = new ControleQuartos();
		reservas = new ControleReservas(this, quartos, out);
		hospedes = new ControleHospedes();
		funcionarios = new ControleFuncionarios();
		ocupacoes = new ControleOcupacao(this, quartos, reservas, out);
		login = new ControleLogin(funcionarios);
		in = new ControleEntrada(this, reservas, quartos, hospedes, funcionarios, ocupacoes, login, out);
	}
	
	public DataHora horaDoSistema(){
		return horaDoSistema;
	}
	
	public void alterarHora(DataHora h){
		horaDoSistema = h;
	}
	
	public void iniciar(){
		in.inicio();
	}
	
	public void criarRoot(String password){
		
		Funcionario root = new Funcionario("root", null, null, null, password); 
		funcionarios.novoFuncionario(root);
	}
	
	public void criarFuncionario(Funcionario f){
		funcionarios.novoFuncionario(f);
	}
	
	public void criarQuarto(Quarto q){
		quartos.novoQuarto(q);
	}
	
	public void criarHospede(Hospede h){
		hospedes.novoHospede(h);
	}
	
	public void criarReserva(Reserva r){
		reservas.novaReserva(r);
	}
}
