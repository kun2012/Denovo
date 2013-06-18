class Fact inherits IO {
	Int fact(Int n) {
		if (n == 1) return n;
		else return (n * fact(n - 1));
	}
	
	Int main() {
		Int m, result;
		m = read();
		if (m > 1) result = fact(m);
		else result = 1;
		write(result);
		return 0;
	}
}
