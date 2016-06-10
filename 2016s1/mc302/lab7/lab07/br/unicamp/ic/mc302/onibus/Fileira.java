package br.unicamp.ic.mc302.onibus;

import java.util.ArrayList;

public abstract class Fileira {

	private ArrayList<Poltrona> poltronas;
		
	public Fileira() {	
		this.poltronas = new ArrayList<Poltrona>();
	}
	
	protected void setPoltronas(ArrayList<Poltrona> poltronas){
		this.poltronas = poltronas;
	}
	
	public boolean ocupar(int coluna){
		return this.poltronas.get(coluna).ocupar();
	}

	public boolean desocupar(int coluna){
		return this.poltronas.get(coluna).desocupar();
	}
	
	public boolean ocupada(int coluna){
		return this.poltronas.get(coluna).ocupada();
	}
}
