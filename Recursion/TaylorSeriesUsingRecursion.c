#include<stdio.h>

double taylorSeries(int x, int n) {
	
	static double p=1, f=1;
	double result;
	if (n == 0) {
		return 1;
	}
	else {
		result = taylorSeries(x, n-1);
		p *= x;
		f *= n;
		return result + p / f; 
	}
}

int main() {
	
	printf("Enter x and n: ");
	int x, n;
	scanf("%d %d", &x, &n);
	printf("%lf", taylorSeries(x, n));
	return 0;
	
}
