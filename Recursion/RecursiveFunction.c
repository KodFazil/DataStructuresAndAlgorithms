#include<stdio.h>

recursiveFunct1(int x) {
	if( x > 0) {
		printf("%d ", x);
		recursiveFunct1(x - 1); 
	}
}

recursiveFunct2(int x) {
	if( x > 0) {
		recursiveFunct2(x - 1);
		printf("%d ", x);
	}
}
int main() {
	int x = 5;
	recursiveFunct1(x);
	printf("\n");
	recursiveFunct2(x);
	return 0;
}
