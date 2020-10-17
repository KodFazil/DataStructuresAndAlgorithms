#include<stdio.h>

int sumofN(int n) {
	
	if(n == 0) return 0;
	else return sumofN(n-1) + n;
	
}

 int main() {
 	printf("Enter n: ");
 	int n;
 	scanf("%d", &n);
 	printf("%d", sumofN(n));
 }
