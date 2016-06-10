package br.unicamp.ic.mc302.motor;

public class Principal {

	public static void main(String[] args) {
		
		int combustivel = 100;
		
		// Cria objetos
		Bateria bat = new Bateria(100);
		Injetor inj = new Injetor(combustivel);
		VelaDeIgnicao vela = new VelaDeIgnicao();
		
		// Verifica carga da bateria
		if(bat.getCarga() > VelaDeIgnicao.cargaMinima){
		
			// Injeta combustivel
			inj.injetar();
			// Aciona ignicao
			vela.ignicao(bat.getCarga());	
		}	
		
	}
	
}