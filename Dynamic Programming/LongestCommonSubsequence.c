#include<stdio.h>

int max(int a, int b) {
	return a > b ? a : b;
}

int main() {
	
	char str1[2] = "bd";
	char str2[4] = "abcd";
	int table[3][5] = {0};
	int i, j, n = 2, m = 4;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= m; j++) {
			if (str1[i-1] == str2[j-1]) table[i][j] = table[i-1][j-1] + 1;
			else table[i][j] = max(table[i][j-1], table[i-1][j]);	
		}
	}
	
	for (i = 0; i <= n; i++) {
		for (j = 0; j <= m; j++) {
			printf("%d ", table[i][j]);
		}
		printf("\n");
	}
	
	printf("Longest Common Subsequence %d", table[n][m]);
	
	return 0;
}
