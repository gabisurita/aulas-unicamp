package br.unicamp.ic.mc302.telefone;

@SuppressWarnings("serial")
public class TelefoneEvent extends java.util.EventObject {

	private String numero;
	private String data;
	private String hora;
	
	public TelefoneEvent(Telefone source, String numero, String data, String hora) {
		super(source);
		
		this.numero = numero;
		this.data = data;
		this.hora = hora;
	}
	
	public String numero(){
		return numero;
	}
	
	public String data(){
		return data;
	}
	
	public String hora(){
		return hora;
	}
	
	
}
