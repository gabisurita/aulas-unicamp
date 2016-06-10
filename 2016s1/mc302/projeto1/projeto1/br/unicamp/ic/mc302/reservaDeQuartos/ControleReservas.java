package br.unicamp.ic.mc302.reservaDeQuartos;

import java.util.HashMap;

import br.unicamp.ic.mc302.dataHora.Periodo;

public class ControleReservas {
	
	public static int HorasSemMulta = 12;
	
	private ControleSaida out;
	private ControleQuartos quartos;
	private SistemaReservas sistema;
	
	private HashMap<Integer,Reserva> reservas;
	private int nReserva = 1;
	
	
	public ControleReservas(SistemaReservas sistema, ControleQuartos quartos, ControleSaida out) {
		
		this.out = out;
		this.quartos = quartos;
		this.sistema = sistema;
		
		reservas = new HashMap<Integer,Reserva>();
	}
	
	public Reserva buscaReserva(int id){
		return reservas.get(id);
	}
	
	public String listaReservas(){
		return reservas.toString(); 
	}

	public int novoNumeroReserva(){
		return nReserva++;
	}
	
	public boolean novaReserva(Reserva r){
		
		if(r.hospede() == null){
			out.println("Hospede invalido");
			return false;
		}
		
		if(r.duracao().inicio().depois(r.duracao().fim())){
			out.println("Periodo invalido");
			return false;
		}
		
		if(r.duracao().inicio().antes(sistema.horaDoSistema())){
			out.println("Periodo invalido");
			return false;
		}
		
		
		int disponiveis = quartos.nQuartos(r.tipoQuarto()-1);
		Object[] keys = reservas.keySet().toArray();
		
		for(Object k : keys){
			
			int id = ((Integer)k).intValue();
			Reserva res = reservas.get(id);
			
			if(res.duracao().cruza(r.duracao()) && res.tipoQuarto()==r.tipoQuarto()){
				disponiveis--;
			}
			
			if(disponiveis <= 0){	
				out.println("Nao ha vagas para este tipo");
				return false;
			}
		}
			
		reservas.put(r.id(), r);
		return true;
	}
	
	public void editarReserva(Reserva r, Periodo p){
		
		r.alterarPeriodo(p);
		reservas.put(r.id(), r);
	}
	
	public void editarReserva(Reserva r, int tipo){

		r.alterarTipoQuarto(tipo);
		reservas.put(r.id(), r);
	}
	
	public void removerReserva(Reserva r){
		
		int inicio = r.duracao().inicio().diferenca(sistema.horaDoSistema());
		
		if(inicio<60*HorasSemMulta && inicio > 0)
			out.println("Cobrar multa de"+ r.multa());
		
		reservas.remove(r.id());
	}
}
