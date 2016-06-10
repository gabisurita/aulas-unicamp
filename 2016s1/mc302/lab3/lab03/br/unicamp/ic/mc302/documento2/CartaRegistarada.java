package br.unicamp.ic.mc302.documento2;

public class CartaRegistarada extends Carta2 {

	private String dataDeEnvio;
	private String localDeEnvio;
	
	public CartaRegistarada(String dataDeEnvio, String localDeEnvio) {
		
		super();	
		
		this.dataDeEnvio = dataDeEnvio;
		this.localDeEnvio = localDeEnvio;
	}

}
