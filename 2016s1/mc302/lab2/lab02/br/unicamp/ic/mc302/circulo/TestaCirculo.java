package br.unicamp.ic.mc302.circulo;

// arquivo TestaCirculo.java
class TestaCirculo {
    public static void main (String args[ ]) {

    	Circulo c1, c2, c3;
    	
    	c1 = new Circulo(3, 3, 1);
    	c2 = new Circulo(2, 1, 4);
    	c3 = c1; // mesmo objeto!
    	
    	// Impressao dos atributos x e y
    	System.out.println("c1: (" + c1.x + ", " + c1.y + ")");
    	System.out.println("c2: (" + c2.x + ", " + c2.y + ")");
       	System.out.println("c3: (" + c3.x + ", " + c3.y + ")");
   	
       	/*
       	 * Manter os atributos como publicos em POO não é considerada uma 
       	 * boa prática pois permite mdificações no objeto que não sejam por
       	 * meio da interface pública de sua classe, o que pode violar 
       	 * propriedades intrinsecas daquele objeto e danificar a robustez
       	 * da implementação.
       	 */
       	
    	int circ = (int) c1.circunferencia();
    	System.out.print("Raio de c1: " + c1.getRaio());
    	System.out.println("; Circunferência de c1: "+ circ);
    }

} // Fim da classe TestaCirculo
 
