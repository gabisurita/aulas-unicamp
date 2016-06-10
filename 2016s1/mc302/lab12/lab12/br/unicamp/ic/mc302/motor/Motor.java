package br.unicamp.ic.mc302.motor;

public class Motor {

	public static int carga = 100;
	public static int combustivel = 100;
	
	private Bateria bat;
	private Injetor inj;
	private VelaDeIgnicao vela;
	
	public Motor() {
		
		bat = new Bateria(carga);
		inj = new Injetor(combustivel);
		vela = new VelaDeIgnicao();
	}
	
	public void ligar(){
		// Verifica carga da bateria
		if(bat.getCarga() > VelaDeIgnicao.cargaMinima){
		
			// Injeta combustivel
			inj.injetar();
			// Aciona ignicao
			vela.ignicao(bat.getCarga());	
		}	
	}
}
