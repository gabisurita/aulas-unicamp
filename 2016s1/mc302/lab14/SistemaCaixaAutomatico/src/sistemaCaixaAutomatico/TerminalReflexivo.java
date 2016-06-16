package sistemaCaixaAutomatico;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.Reader;
import java.io.StreamTokenizer;

import java.lang.reflect.Field;
import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;

public class TerminalReflexivo {

	private ControladorCaixa controladorCaixa; // associação entre terminal e controladorcaixa

	public TerminalReflexivo(int senhaCaixa) {
		controladorCaixa = new ControladorCaixa(senhaCaixa);
	}

	private int getInt(String str) {

		System.out.println(str);

		// lê os valores digitados na entrada padrão
		Reader r = new BufferedReader(new InputStreamReader (System.in));
		StreamTokenizer st = new StreamTokenizer(r);

		try {
			st.nextToken();
		}
		catch (IOException e) {
			System.out.println("Erro na leitura do teclado");
			return(0);
		}

		return((int)st.nval);
	}


	
	public void iniciarOperacao (){
		int op;	// código da operação solicitada 


		while(true){
			op=getInt("\n"
					+ "1. Hierarquia de ContaCor\n"
					+ "2. Atributos de classe ContaCor\n"
					+ "3. Métodos públicos de Contacor\n"
					+ "4. Saque");
			switch (op) {
				
				case 1:
					System.out.println("Imprimindo Hierarquia de classes:");
					
					Class c = ContaCor.class;
					
					while(c != null){
						System.out.println(c.getName());
						c = c.getSuperclass();
					}				
					
					break;
					
					
				case 2:
					System.out.println("Imprimindo atributos declarados:");
					
					Field[] atts = ContaCor.class.getDeclaredFields();
					
					for(Field at: atts){
						System.out.println(at.getName());	
					}
					
					break;
					
				case 3:
					System.out.println("Imprimindo métodos públicos:");
					
					Method[] pmets = ControladorCaixa.class.getMethods(); 
					
					for(Method m: pmets){
						System.out.println(m.getName());	
					}
					
					break;
				
				case 4:
					
					Class metaCont = controladorCaixa.getClass();
					
					try{
						Method metaSaque = metaCont.getMethod("efetuarSaque",int.class,int.class,float.class);
						
						Object saqueEfetuado = metaSaque.invoke(
								controladorCaixa,
								getInt("número da conta"),
								getInt("senha"),
								getInt("valor")
						);
					
						if ((boolean)saqueEfetuado)		// testa se saque foi aceito 
							System.out.println("Pode retirar o dinheiro");
						else 
							System.out.println("Pedido de saque recusado");
					}
					
					catch (SecurityException e) {e.printStackTrace();}
					catch (NoSuchMethodException e) {e.printStackTrace();}
					catch (IllegalAccessException e) {e.printStackTrace();}
					catch (IllegalArgumentException e) {e.printStackTrace();}
					catch (InvocationTargetException e) {e.printStackTrace();}
					
					break;
					
					
				case 9:
					return;
			}
		}
	}
}
