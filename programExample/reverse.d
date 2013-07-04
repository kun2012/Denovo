class Reverse inherits IO {
	Int main() {
		Int[] a = new Int[100];
		Int n = read();
		Int i = 0;
		while(i < n) {
			a[i] = read();
			i = i + 1;
		}
		while(i > 0) {
			i = i - 1;
			write(a[i]);
		}
		return 0;
	}
}
