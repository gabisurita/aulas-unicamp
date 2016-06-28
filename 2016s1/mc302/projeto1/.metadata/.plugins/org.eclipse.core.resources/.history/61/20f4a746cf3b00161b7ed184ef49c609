package br.unicamp.ic.mc302.reservaDeQuartos;

import java.util.ArrayList;
import java.util.HashMap;

public class ControleOcupacao {
	
	private SistemaReservas sistema;
	private ControleReservas reservas;
	private ControleQuartos quartos;
	private ControleSaida out;
	
	private HashMap<Quarto, Ocupacao> ocupacoes;
	
	public ControleOcupacao(SistemaReservas sistema, ControleQuartos quartos, ControleReservas reservas, ControleSaida out) {
	
		this.sistema = sistema;
		this.quartos = quartos;
		this.reservas = reservas;
		this.out = out;
	
		ocupacoes = new HashMap<Quarto, Ocupacao>();
	
	}

	public String listaOcupacoes(){
		return ocupacoes.toString(); 
	}
	
	public void ocupar(Reserva r) {
		
		ArrayList<Quarto> qIDs = quartos.buscaQuartoTipo(r.tipoQuarto());
		
		Quarto vazio = null;
		
		for(Quarto q : qIDs){
			
			Ocupacao oc = ocupacoes.get(q);
			
			if(oc == null){
				vazio = q;
				break;
			}
		}
		
		if(vazio == null){
			out.println("Overbooked!\n");
			return;
		}
			
		Ocupacao ocp = new Ocupacao(vazio, r, sistema.horaDoSistema());
		ocupacoes.put(vazio, ocp);
		
		out.println("Quarto: "+vazio.id());
	}
	
	
	public void desocupar(Quarto q) {
		
		Ocupacao oc = ocupacoes.remove(q);
		reservas.removerReserva(oc.reserva());
		
		int estadia = sistema.horaDoSistema().diferenca(oc.inicio());
		int dias = estadia/1440;
		
		// Adciona uma diaria por atraso
		if(dias*1440 < estadia)
			dias++;
		
		out.println("Diarias: "+ dias);
		out.println("Preco total da estadia: " + q.preco() * dias +"\n");
	}
	
}
