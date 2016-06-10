package br.unicamp.ic.mc302.onibus;

import java.util.ArrayList;

public class OnibusLeito extends Onibus {

	public OnibusLeito(int id) {
		super(id);
		this.defineFileiras();

	}

	public void defineFileiras() {
		
		ArrayList<Fileira> fileiras = new ArrayList<Fileira>();
		
		for(int i=0; i<5; i++){
			fileiras.add(new FileiraLeito(4));
		}
		
		super.setFileiras(fileiras, 5, 4);
	}

}
