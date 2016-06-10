package br.unicamp.ic.mc302.onibus;

import java.util.ArrayList;

public class FileiraLeito extends Fileira {

	public FileiraLeito(int nPoltronas) {
		
		super();	
		ArrayList<Poltrona> poltronas = new ArrayList<Poltrona>();
		
		for(int i=0; i<nPoltronas; i++)
			poltronas.add(new PoltronaLeito());
		
		super.setPoltronas(poltronas);
	}

}
