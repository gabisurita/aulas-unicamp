package sistemaCaixaAutomatico;

public class ContaPoupanca extends ContaCor {

	private float rendimento = (float)0.005;
	
	public ContaPoupanca(String titular, float saldoAtual, int numConta, int senha) {
		super(titular, saldoAtual, numConta, senha);
	}
	
	public void atualizarRendimento(float rend){
		this.rendimento = rend;
	}
	
	public void render(){
		creditarValor("Rendimento de poupanca", obterSaldo()*rendimento);
	}

}