#include<stdio.h>

void funct(int n) {
	
	if(n>0) {
		printf("%d ", n);
		funct(n-1);
		funct(n-1);	
	}
}

int main() {
	
	funct(3);
}
