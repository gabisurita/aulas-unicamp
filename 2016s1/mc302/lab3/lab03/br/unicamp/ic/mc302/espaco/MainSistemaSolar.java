package br.unicamp.ic.mc302.espaco;

public class MainSistemaSolar {

	public static void main(String[] args) {
		SistemaPlanetario s = new SistemaPlanetario(1, 5, 1);
		
		s.defineEstrela("Sol", 0, 0);
		s.defineCometa("Halley", 0, 0, 0);
		
		s.definePlanetaTerrestre("Mercurio", 0, 0, 0, 0);
		s.definePlanetaTerrestre("Venus", 0, 0, 1, 0);
		s.definePlanetaTerrestre("Terra", 0, 0, 2, 1);
		s.defineLua("Lua", 0, 0, 2, 0);
		s.definePlanetaTerrestre("Marte", 0, 0, 3, 0);
		s.definePlanetaGasoso("Jupiter", 0, 0, 4, 36);
		
		s.imprimePlanetas();
		System.out.println(s.toString());
	}

}