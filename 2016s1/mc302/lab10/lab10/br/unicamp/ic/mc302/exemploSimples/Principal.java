package br.unicamp.ic.mc302.exemploSimples;

public class Principal {

	public static void main(String args[]) {

		I1 obj = new C1();
		I1 obj2 = new C2();
		
		obj.m1();
		obj2.m1();
		
		I2 obj3 = new C1();	
		obj3.m2();
	
		I3 obj4 = new C3();
		obj4.m1();
		obj4.m3();
	}
}