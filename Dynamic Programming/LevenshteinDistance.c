#include<stdio.h>

int min(int a, int b, int c) {
	int minn = a < b ? a : b;
	minn = minn < c ? minn : c;
	return minn; 
}

int main() {
	
	char kelime1[6] = "sunday";
	char kelime2[8] = "saturday";
	int table[7][9] = {0};
	int n = 6, m = 8;
	int i, j;
	for (i = 1; i < n + 1; i++) table[i][0] = i;
	for (j = 1; j < m + 1; j++) table[0][j] = j;
	int substitionCost = 0;
	for (j = 1; j <= m; j++) {
		for (i = 1; i <= n; i++) {
			if (kelime1[i - 1] == kelime2[j - 1]) substitionCost = 0;
			else substitionCost = 1;
			table[i][j] = min(table[i-1][j] + 1, table[i][j - 1] + 1, table[i-1][j-1] + substitionCost);
		}
	}
	printf("Final table:\n\n");
	for (i = 0; i < n + 1; i++) {
		for (j = 0; j < m + 1; j++) {
			printf("%d ", table[i][j]);
		}
		printf("\n");
	}
	printf("\nDifference is: %d", table[n][m]);
	
	return 0;
}
