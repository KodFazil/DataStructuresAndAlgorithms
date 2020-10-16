#include<stdio.h>

int funct(int n) {
	if(n>0) {
		return funct(n-1) + n;
	}
	return 0;
}

int funct2(int n) {
	
	static int x = 0;
	if(n>0) {
		x++;
		return funct2(n-1) + x;
	}  
	return 0;
}


int main() {
	
	int a = 5;
	printf("%d ", funct(a));
	printf("%d", funct2(a));
	
	return 0;
}
