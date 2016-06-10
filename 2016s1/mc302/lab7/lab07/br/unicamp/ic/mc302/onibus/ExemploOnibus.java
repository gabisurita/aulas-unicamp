package br.unicamp.ic.mc302.onibus;

import java.util.Scanner;
import java.util.ArrayList;

public class ExemploOnibus {

	public static void main(String[] args) {
		
		ArrayList<Onibus> onibuses = new ArrayList<Onibus>();
		
		onibuses.add(new OnibusConvencional(1));
		onibuses.add(new OnibusLeito(2));

		Scanner in = new Scanner(System.in);
		
		while(true){
			System.out.println("Selecione o onibus");
			int nOnibus = in.nextInt();
			
			if(nOnibus == -1)
				break;
		
			System.out.println("Selecione a poltrona");
			
			int fileira = in.nextInt() - 1;
			int coluna = in.next().toCharArray()[0] - 'A' - 1;
			
			if(onibuses.get(nOnibus).ocupar(fileira, coluna)){
				System.out.println("Reservada com sucesso");
			}
			
			else{
				System.out.println("Poltrona ocupada, tente outra");
				System.out.println(onibuses.get(nOnibus));
			}
		}
		
		in.close();
	}

}
