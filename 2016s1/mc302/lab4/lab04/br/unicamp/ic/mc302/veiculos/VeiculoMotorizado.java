package br.unicamp.ic.mc302.veiculos;

public class VeiculoMotorizado {
	
	private int lotacao;
    private int numPortas;
    private String marca;
    private String modelo;
    private String placa;
    private int anoModelo;
    
    private Motor2 motor;
    private TanqueCombustivel2 tanque;
    

    public VeiculoMotorizado(int lot, int num, int ano, String mar, String mod, String pl) {
        marca=mar;
        modelo=mod;
        placa=pl;
        anoModelo=ano;
        lotacao=lot;
        numPortas=num;
        
        motor = new Motor2(this);
        tanque = new TanqueCombustivel2(this);
    }
    
    public void ligar(){
    	motor.ligar();
    	tanque.gastar(1);
    }

    public void desligar(){
    	motor.desligar();
    }
    
    public boolean estaLigago(){
    	return motor.estaLigado();
    }

    public void andar(){
    	tanque.gastar(1);
    }
    
    public int mostrarCombutivel(){
    	return tanque.leitura();
    }
}
