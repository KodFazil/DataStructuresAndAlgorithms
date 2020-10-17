#include<stdio.h>

int factorial(int n) {
	
	if (n == 1) {
		return 1;
	}
	else {
		return factorial(n-1) * n; 
	}
}

int main() {
	
	printf("Enter n: ");
	int n;
	scanf("%d", &n);
	int result = factorial(n);
	printf("%d", result);
		
	return 0;
}
