package br.unicamp.ic.mc302.reservaDeQuartos;

import java.util.ArrayList;
import java.util.HashMap;

public class ControleQuartos {
	
	public static int TIPOS_DE_QUARTO = 3;
	
	private HashMap<Integer,Quarto> quartos;
	private ArrayList<Quarto> tipos[];
 	private int[] nQuartos; // numero de quartos de cada tipo;

	public ControleQuartos() {
		
		tipos = new ArrayList[TIPOS_DE_QUARTO];
		
		for(int i=0; i<TIPOS_DE_QUARTO; i++){
			tipos[i] = new ArrayList<Quarto>();
		}
		
		quartos = new HashMap<Integer,Quarto>();
		nQuartos = new int[TIPOS_DE_QUARTO];
	}
	
	public Quarto buscaQuarto(int id){
		return quartos.get(id);
	}
	
	public ArrayList<Quarto> buscaQuartoTipo(int tipo){
		return tipos[tipo-1];
	}
	
	public String listaQuartos(){
		return quartos.toString();
	}
	
	public void novoQuarto(int tipo, double preco, int capacidade, String descricao){
		Quarto novo = GeradorQuarto.novoQuarto(tipo, preco, capacidade, descricao);
		quartos.put(novo.id(), novo);
		tipos[novo.id()-1].add(novo);
	}
		
	public void removerQuarto(Quarto q){
		quartos.remove(q.codigo());
		tipos[q.id()-1].remove(q);
	}
	
	public int nQuartos(int i){
		return nQuartos[i];
	}
	
}
