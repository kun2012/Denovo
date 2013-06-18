class A {
	void main() {
//		Int a = 3, c = 4, d = c, e;
//		e = a * c + 4 - a / (e + 10);
/*		c = -e;
		Int i, j, k;
		if (i <= j || i > j || i == k)
			i = j;*/
	}
/*	
	void hello() {
		Int p = 1, q = 2;
		if (p < q && 3 < 4) p = q;

		if (6 >= 1 || p == q) q = p;

		if (!(2 != 4)) p = p * q;
	}*/

	Int min(Int a, Int b) {
		if (a < b) return a;
		else return b;
	}

	Int sum(Int n) {
		Int i = 1, s = 0;
		while(i <= n) {
			s = s + i;
			if (i == n/2) continue;
			else break;
			if (i == 10) {
				Int j = 0;
				while(j < n) {
					j = j + 1;
					if (j == 3) break;
					else continue;
					j = j + 2;
				}
			}
			i = i + 1;
		}
		return s;
	}
	Int threeMin(Int a, Int b, Int c) {
		Int t = min(a, b);
		return min(t, c);
	}
	
}
