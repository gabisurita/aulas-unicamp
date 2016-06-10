package br.unicamp.ic.mc302.onibus;

import java.util.Scanner;

public class ReservaLugares {

	public static void main(String[] args) {

		Onibus meuOnibus = new Onibus(4, 40);
		Scanner in = new Scanner(System.in);
		
		do{
			
			// Separar lugar de coluna por espaco. Ex: 13 B
			int lugar = in.nextInt();
			char coluna  = in.next().charAt(0);
			
			if(lugar < 0){
				break;
			}
			
			if(meuOnibus.estaOcupada(lugar, coluna)){
				System.out.println("Poltrona ocupada! Tente outra.");
			}
			else{
				meuOnibus.ocupar(lugar, coluna);
				System.out.println("Reserva efetuada!");
			}
			
		} while(true);	
		
		in.close();
	}
}
