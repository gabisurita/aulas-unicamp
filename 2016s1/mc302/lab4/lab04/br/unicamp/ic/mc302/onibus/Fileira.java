package br.unicamp.ic.mc302.onibus;

public class Fileira {

	int nPoltronas;
	Poltrona poltronas[];
	
	public Fileira(int nPoltronas){
		
		this.nPoltronas = nPoltronas;
		poltronas = new Poltrona[nPoltronas];
		
		for (int i=0; i<nPoltronas; i++){
			poltronas[i] = new Poltrona();
		}
	}
	
	public void ocupar(int n){
		poltronas[n].ocupar();
	}
	
	public void desocupar(int n){
		poltronas[n].desocupar();
	}
	
	public boolean estaOcupada(int n){
		return poltronas[n].estaOcupada();
	}
}
