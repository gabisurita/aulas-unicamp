package geometria;


public class Reta {

  Ponto a,b;

  public Reta(float ax,float ay, float bx, float by){
  a=new Ponto(ax,ay);
  b=new Ponto(bx,by);
  }

  public float distancia(Ponto ap){
  //metodo nao implementado, acesse livremente os atributos do argumento
  // Ponto de modo a calcular a sua distancia a esta reta
  return 0.0f;
  }

  public void mostra(){
   a.mostra();
   b.mostra();
   }

}
