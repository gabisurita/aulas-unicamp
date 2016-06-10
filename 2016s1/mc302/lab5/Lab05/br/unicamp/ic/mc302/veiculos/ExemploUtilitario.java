package br.unicamp.ic.mc302.veiculos;

public class ExemploUtilitario {

	public static void main(String[] args) { 
		
		VeiculoUtilitario suv = new VeiculoUtilitario();
		
		/* Métodos da classe Veiculo */
		suv.definePeso(2000);
		suv.emplaca("FQW-1345");
		
		/* Métodos da classe VeiculoPasseio */
		suv.defineBancos(5);
		
		/* Métodos da classe SUV criados por "refatoracao" */
		suv.defineCargaUtil(1000);
		
		
		suv.display();
	}

}
