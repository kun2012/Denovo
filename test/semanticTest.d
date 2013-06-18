class Helloworld inherits A{
	Int ab = "ab", cd;
	Int ok = 10;
	
	void main(Int a, Int b) {
		Int c;
		Int e, f, b = 2, g = "hello";
		String s = "world", t;
		s = 10;
		ok = 3;
		ok = "ok";
		attriA = "variable from father";
		
	}
	Int b() {
		Int[] a;
		Int b;
		b = a[10];
		return "hello";
	}
	
}

class A {
	String attriA;
	void afun() {
	}
}

class Student inherits A{
	Int hello(Int a, Int b) {
		Int c = a + b;
		return c;
	}
	void hello() {
	}
	Int main() {
		String s = hello(1, 2); //error
		hello(); 
		hello("a", 1);//error
		afun();
	}
}
