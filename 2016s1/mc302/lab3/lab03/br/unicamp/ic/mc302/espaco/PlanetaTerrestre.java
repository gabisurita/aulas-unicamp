package br.unicamp.ic.mc302.espaco;

public class PlanetaTerrestre extends Planeta {
	
	protected boolean atmosfera;
	protected boolean habitavel;
	protected boolean explorado;

	public PlanetaTerrestre(String nome, double massa, double diametro) {
		super(nome, massa, diametro);
		
	}
	
	public void explorar(boolean atmosfera, boolean habitavel){
		this.explorado = true;
		this.atmosfera = atmosfera;
		this.habitavel = habitavel;
	}

}
