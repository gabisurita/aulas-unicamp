package br.unicamp.ic.mc302.reservaDeQuartos;

import br.unicamp.ic.mc302.dadosPessoais.*;
import br.unicamp.ic.mc302.dataHora.DataHora;

public class ExemploHotel {

	public static void main(String[] args) {
		
		SistemaReservas s = new SistemaReservas();
		
		s.alterarHora(new DataHora(26, 04, 2016, 17, 10));
		
		// dois funcionários
		s.criarFuncionario(new Funcionario("adm1", new Documento(), new Endereco(), "12345678", "1"));
		s.criarFuncionario(new Funcionario("adm2", new Documento(), new Endereco(), "87654321", "2"));
		
		// tres hospedes A,B,C
		s.criarHospede(new Hospede(
				"A",
				new Documento("12345678", Documento.RG),
				new Endereco("rua 1", 123, "", "aaaa", "campinas", "sp", "1234567"),
				"brasileiro",
				"a@aaa.com",
				"123456788"
		));
		s.criarHospede(new Hospede(
				"B",
				new Documento("87654321", Documento.CPF),
				new Endereco("rua 2", 321, "ap 11", "bbbb", "campinas", "sp", "8765432"),
				"brasileiro",
				"b@bbb.com",
				"123456788"
		));
		s.criarHospede(new Hospede(
				"C",
				new Documento("12345678", Documento.passaporte),
				new Endereco("rua 1", 123, "", "aaaa", "campinas", "sp", "1234567"),
				"argentino",
				"a@aaa.com",
				"123456788"
		));
		
		// tres quartos
		s.criarQuarto(new QuartoSolteiro(1, 240, 2, "Quarto solteiro standard"));
		s.criarQuarto(new QuartoCasal(2, 300, 3, "Quarto casal standard"));
		s.criarQuarto(new QuartoSuiteLuxo(3, 500, 4, "Suite casal luxo"));
		
		s.iniciar();
	
	}

}