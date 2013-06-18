class Finbonacci inherits IO {
	Int main() {
		Int a = 1, b = 1, n;
		Int i = 0;
		n = read();
		while(i < n) {
			write(a);
			Int c = a + b;
			a = b;
			b = c;
			i = i + 1;
		}
		return 0;
	}
}
