#include<stdio.h>

double hornerTaylor(int x, int n) {
	
	static double s = 1;
	if (n==0)
		return s;
	else {
		s = 1 + s*x/n;
		return hornerTaylor(x, n-1);
	}
		 
}

int main() {
	
	printf("%lf", hornerTaylor(1, 10));
	return 0;
}
