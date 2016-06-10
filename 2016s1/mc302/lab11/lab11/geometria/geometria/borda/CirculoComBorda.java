package geometria.borda;

import geometria.Circulo;

public class CirculoComBorda extends Circulo {

  float borda;

  public CirculoComBorda() {
    super();
    this.borda = 0;
  }
  
  public CirculoComBorda(float ax, float ay, float ar, float bw) {
    super(ax,ay,ar);
    this.borda = bw;
  }

  public float obterEspessuraBorda(){
    return borda;
  }
  
  public void alterarEspessuraBorda(float bw){
    borda = bw;
  }

  public void mostra(){
    System.out.println("Espessura da borda: "+borda);
    super.mostra();
  }

  public static void main(String args[]) {
    Circulo circ = new Circulo(1,1,1);
    circ.mostra();
  }
}
