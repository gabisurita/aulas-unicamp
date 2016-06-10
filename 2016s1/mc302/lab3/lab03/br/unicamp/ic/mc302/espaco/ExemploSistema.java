package br.unicamp.ic.mc302.espaco;

public class ExemploSistema {

	public static void main(String[] args) {
		
		Estrela sol = new Estrela("Sol",3000000, 600000);
		
		Planeta planetas[] = new Planeta[8];
		
		planetas[0] = new PlanetaTerrestre("Mercurio", 20000, 29000);
		planetas[1] = new PlanetaTerrestre("Venus", 29000, 42000);
		planetas[2] = new PlanetaTerrestre("Terra", 36000, 53000);
		planetas[3] = new PlanetaTerrestre("Marte", 29000, 46000);
		planetas[4] = new PlanetaGasoso("Jupiter", 100000, 100000);
		planetas[5] = new PlanetaGasoso("Saturno", 70000, 70000);
		planetas[6] = new PlanetaGasoso("Urano", 80000, 80000);
		planetas[7] = new PlanetaGasoso("Netuno", 80000, 80000);
		
		
		
	}

}
