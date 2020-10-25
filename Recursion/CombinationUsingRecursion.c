#include<stdio.h>

int fact(int n) {
	
	if (n == 0) {
		return 1;
	}
	
	else {
		return fact(n-1) * n;	
	}
}

int Ifact(int n) {
	int i, result = 1;
	for (i=1; i<=n;i++) {
		result *= i;
	} 	
	return result;
}

int comb(int n, int r) {
	
	int nfact, rfact, nrfact;
	nfact = fact(n);
	rfact = Ifact(r);
	nrfact = fact(n-r);
	return nfact / (rfact * nrfact);	
}

int main() {
	
	printf("%d", comb(5, 3));
	return 0;
}
