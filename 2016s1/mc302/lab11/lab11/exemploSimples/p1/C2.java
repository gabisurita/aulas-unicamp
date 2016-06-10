package p1;

import p1.p2.*;

public class C2 {

    public void m2()
    {
        System.out.println("Metodo m2() da classe C2 executado!");
        
        C3 obj = new C3();
        obj.m3();
    }
}
