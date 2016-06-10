package br.unicamp.ic.mc302.veiculos;

public class VeiculoUtilitario extends VeiculoPasseio {

	Carga cargaUtil;
	
	public VeiculoUtilitario(){
		cargaUtil = new Carga();
	}
	
	public void defineCargaUtil(int c){
		cargaUtil.defineCapacidade(c);
	}
	
	public void display(){
		super.display();
		cargaUtil.display();
	}
	
}
