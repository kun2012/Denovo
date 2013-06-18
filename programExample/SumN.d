class SumN inherits IO {
	Int main() {
		Int i, n, s;
		n = read();
		s = 0;
		for (i = 1; i <= n; i = i + 1)
			s = s + i;
		write(s);
		return 0;
	}
}
