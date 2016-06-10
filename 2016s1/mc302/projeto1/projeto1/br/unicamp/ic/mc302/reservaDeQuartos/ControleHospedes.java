package br.unicamp.ic.mc302.reservaDeQuartos;

import java.util.HashMap;

public class ControleHospedes {
		
	private HashMap<String,Hospede> hospedes;

	public ControleHospedes() {
		hospedes = new HashMap<String, Hospede>();
	}
	
	public Hospede buscaHospede(String nome){
		return hospedes.get(nome);
	}
		
	public String listaHospedes(){
		return hospedes.toString();
	}
	
	public void novoHospede(Hospede h){
		hospedes.put(h.nome(), h);
	}
		
	public void removerHospede(Hospede h){
		hospedes.remove(h.nome());
	}
	
}