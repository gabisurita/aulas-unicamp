package br.unicamp.ic.mc302.contaCor;

class ContaCor {
    private int estado; // 1 = conta ativa ; 2 = conta inativa
    private int senha;
    private int numConta;
    private String titular;
    public double saldoAtual;
    //private double saldoAtual;
    
    
    public static final int ATIVA = 1;
    public static final int INATIVA = 2;

    public boolean creditaValor (double val) {
        if (estado!=ATIVA) return(false); // conta deve estar ativa
        if (val<=0) return (false); // val>0;
        saldoAtual+= val; // credita valor;
        return(true); // opera��o terminada com sucesso
    } // fim de creditaValor( )

    public boolean debitaValor (double val, int pwd) {
        if (estado!=ATIVA) return(false); // conta deve estar ativa
        if (val<=0) return (false); // val>0;
        if (pwd!=senha) return (false); // senha deve ser v�lida
        if (val>saldoAtual) return (false); // val<= saldoAtual
        saldoAtual -= val; //debita valor
        if(saldoAtual ==0) estado=INATIVA; // se saldo=0, torna conta inativa
        return(true);
    } // fim de debitaValor( )

    public double getSaldo (int pwd) {
        if (estado!=ATIVA) return(-1); // conta deve estar ativa
        if (pwd!=senha) return(-1); //senha deve ser v�lida
        return(saldoAtual);
    } // fim de getSaldo( )

    public void transferir(ContaCor Destino, double val, int pwd){
    	// Se o o valor estiver disponível na conta da fonte 
    	if(debitaValor(val, pwd)){
    		// Credita o valor na conta de destino
    		Destino.creditaValor(val);
    	}
    }
    
    public ContaCor(String nome, double val, int num, int pwd) {
        titular = nome;
        numConta = num;
        senha = pwd;
        saldoAtual = val;
        estado=1; //conta � ativada quando criada
    } // fim do construtor
} // fim da classe ContaCor
