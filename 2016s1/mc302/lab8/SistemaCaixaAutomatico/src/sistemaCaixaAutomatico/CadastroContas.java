/**
 * Autores: C.M.F. Rubira, P.A. Guerra e L.P. Tizzei
 * 
 * Introdução à Programação Orientada a Objetos usando Java
 * 
 * Estudo de caso: Sistema de Caixa Automático
 * 
 * última modificação: abril de 2013
 */

package sistemaCaixaAutomatico;


public class CadastroContas {
	//Atributos
	  private ContaCor c[];  // vetor de contas
	  
	//Operacoes
	  
	  public CadastroContas () {  // método construtor 
	    c=new ContaCor[5];// o índice zero não é utilizado
	    
	    c[1]=new ContaCor("Ursula",500,1,1);
	    System.out.println("Criada conta 1 senha 1 com 500,00");
	    
	    c[2]=new ContaCor("Mia",500,2,2);
	    System.out.println("Criada conta 2 senha 2 com 500,00");
	    
	    c[3]=new ContaCor("Alfredo",500,3,3);
	    System.out.println("Criada conta 3 senha 3 com 500,00");
	    
	    c[4]=new ContaPoupanca("Alfredo",100,4,4);
	    System.out.println("Criada conta de poupanca 4 senha 4 com 100,00");
	    
	  }
	  
	  public ContaCor buscarConta (int num) {
	    if (num < 1 || num > 4)  // apenas os número 1, 2, 3 e 4 são aceitos
	      return(null);
	    else
	      return(c[num]);
	  }

}