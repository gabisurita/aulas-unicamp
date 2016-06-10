package br.unicamp.ic.mc302.circulo;

// arquivo TestaCirculos.java
class TestaCirculos {
    public static void main (String args[ ]) {
    	
    	// Vetor de circulos
    	Circulo c1[] = new Circulo[5];
    	
    	// Inicializa vetor de circulos
    	for(int i=0; i<c1.length; i++){
    		c1[i] = new Circulo(0,0,i);
    	}
    	
    	for(int i=0; i<c1.length; i++){
    		System.out.print("c1["+ i +"]: Centro (" + c1[i].getX() + ", " + c1[i].getY() + ");  ");
        	System.out.println("Raio: " + c1[i].getRaio());
    	}
    	
    	// Vetor que copia a referencia
    	Circulo c2[];
    	c2 = c1;
    	
    	for(int i=0; i<c2.length; i++){
    		System.out.print("c2["+ i +"]: Centro (" + c2[i].getX() + ", " + c2[i].getY() + ");  ");
        	System.out.println("Raio: " + c2[i].getRaio());
    	}
    	
    	Circulo c3[] = new Circulo[5];
    	
    	// Vetor que copia os objetos
    	for(int i=0; i<c3.length; i++){
    		c3[i] = c1[i];
    	}
    	
    	for(int i=0; i<c3.length; i++){
    		System.out.print("c3["+ i +"]: Centro (" + c3[i].getX() + ", " + c3[i].getY() + ");  ");
        	System.out.println("Raio: " + c3[i].getRaio());
    	}
    	
    	// Modifica c1
    	for(int i=0; i<c1.length; i++){
    		c1[i] = new Circulo(0,0,i*i);
    	}
    	
    	// Imprime os 3 vetores
    	for(int i=0; i<c1.length; i++){
    		System.out.print("c1["+ i +"]: Centro (" + c1[i].getX() + ", " + c1[i].getY() + ");  ");
        	System.out.println("Raio: " + c1[i].getRaio());
    	}
    	
    	
    	for(int i=0; i<c2.length; i++){
    		System.out.print("c2["+ i +"]: Centro (" + c2[i].getX() + ", " + c2[i].getY() + ");  ");
        	System.out.println("Raio: " + c2[i].getRaio());
    	}
    	
    	for(int i=0; i<c3.length; i++){
    		System.out.print("c3["+ i +"]: Centro (" + c3[i].getX() + ", " + c3[i].getY() + ");  ");
        	System.out.println("Raio: " + c3[i].getRaio());
    	}
    	    	
    }

} // Fim da classe TestaCirculo
 
