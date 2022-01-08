#include<stdio.h>

int max(int a, int b) {
	return a > b ? a : b;
}

int main() {
	int dizi[6] = {5, 1, 9, 10, 9, 2};
	int F[7] = {0};
	F[0] = 0, F[1] = dizi[0];
	int i;
	for (i = 2; i < 7; i++) {
		 F[i] = max(dizi[i-1] + F[i-2], F[i-1]);
		 printf("Value: %d, i: %d\n", F[i], i);
	}
	printf("Max value: %d", F[6]);
	
	return 0;
}
