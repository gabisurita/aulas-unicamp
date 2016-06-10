package br.unicamp.ic.mc302.veiculos;

public abstract class VeiculoRodoviario extends Veiculo {

	private String placa;
	
	public VeiculoRodoviario(int ano, String mar, String mod, String pl) {
		super(ano, mar, mod);
		placa = pl;
	}
	
	public void mostra() {
		System.out.println("Placa = " + placa);
	}

}
