class Arith {
	void printOk() {
	}
	void main() {
		Int a = 10, b = 20;
		Int c = a + b;
		c = a * b;
		c = a / b;
		if (a == b) {
			c = a + b * (-b);
		}
		else {
			c = a * a - b;
		}
		while(a != b) break;
		while(a <= b) {
		  if (a < b) continue;
		  else break;
		}
		if (a == b || b >= a && a + b == b)
		 printOk();
	}
}
