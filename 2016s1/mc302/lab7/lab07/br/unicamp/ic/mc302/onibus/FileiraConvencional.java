package br.unicamp.ic.mc302.onibus;

import java.util.ArrayList;

public class FileiraConvencional extends Fileira {

	public FileiraConvencional(int nPoltronas) {
		
		super();	
		ArrayList<Poltrona> poltronas = new ArrayList<Poltrona>();
		
		for(int i=0; i<nPoltronas; i++)
			poltronas.add(new PoltronaConvencional());
		
		super.setPoltronas(poltronas);
	}

}