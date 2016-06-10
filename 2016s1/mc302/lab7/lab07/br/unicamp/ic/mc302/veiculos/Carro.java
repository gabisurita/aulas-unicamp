package br.unicamp.ic.mc302.veiculos;

public class Carro extends VeiculoRodoviario {
 private int lotacao;
 private int numPortas;

  public Carro(int lot, int num, int ano, String mar, String mod, String pl) {
     super(ano,mar,mod,pl);
     lotacao=lot;
     numPortas=num;
  }

  public void mostra(){
     System.out.println("\nTipo-->Carro");
     System.out.println("Lota��o = "+lotacao);
     System.out.println("Numero de Portas = "+numPortas);
     super.mostra();
  }

  public boolean ligar(){
	System.out.println("Carro ligado!");	
	return true;
  }

  public String toString(){
	mostra();
	return "";
  }
}