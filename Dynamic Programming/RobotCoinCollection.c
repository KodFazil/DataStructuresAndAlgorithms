#include<stdio.h>

int max(int a, int b) {
	return a > b ? a : b;
}

int main() {
	
	int coinMatris[7][7] = {{0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 1, 0, 0, 1}, {0, 0, 0, 0, 1, 0, 0}, {0, 0, 1, 0, 0, 1, 0}, 
							{0, 0, 0, 0, 1, 0, 0}, {0, 1, 0, 0, 0, 1, 0}, {0, 0, 0, 1, 0, 0, 1}};
	int i, j;
	printf("Coin Matrix:\n");
	for (i = 0; i < 7; i++) {
		for (j = 0; j < 7; j++)
			printf("%d ", coinMatris[i][j]);
		printf("\n");
	}
	int F[7][7] = {0};
	for (i = 2; i < 7; i++) F[1][i] = F[1][i-1] + coinMatris[1][i];
	for (i = 2; i < 7; i++) {
		F[i][1] = F[i - 1][1] + coinMatris[i][1];
		for (j = 2; j < 7; j++) {
			F[i][j] = max(F[i - 1][j], F[i][j - 1]) + coinMatris[i][j];
		}
	}
	printf("F Matrix:\n");
	for (i = 0; i < 7; i++) {
		for (j = 0; j < 7; j++)
			printf("%d ", F[i][j]);
		printf("\n");
	}
	printf("Max value: %d", F[6][6]);
	
	return 0;
}
