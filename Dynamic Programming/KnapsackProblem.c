#include<stdio.h>

int max(int a, int b) {
	return a > b ? a : b;
}

int main() {
	
	int P[5] = {0, 1, 2 ,5, 6};
	int weight[5] = {0, 2, 3, 4, 5};
	int n = 4, capacity = 8;
	int knapsackMatrix[5][9] = {0};
	int i, wt;
	for (i = 0; i <= n; i++) {
		for (wt = 0; wt <= capacity; wt++) {
			if (i == 0 || wt == 0) {
				knapsackMatrix[i][wt] = 0;
			}
			else if (weight[i] <= wt) {
				knapsackMatrix[i][wt] = max(P[i] + knapsackMatrix[i-1][wt - weight[i]], knapsackMatrix[i-1][wt]);
			}
			else {
				knapsackMatrix[i][wt] = knapsackMatrix[i-1][wt];
			}
		}
	}
	
	printf("Final knapsack table:\n");
	int j;
	for (i = 0; i <= n; i++) {
		for (j = 0; j <= capacity; j++) {
			printf("%d ", knapsackMatrix[i][j]);
		}
		printf("\n");
	}
	
	printf("Max total value: %d\n", knapsackMatrix[n][capacity]);
	
	printf("Which weights taken: \n");
	i = n, j = capacity;
	while (i > 0 && j > 0) {
		if (knapsackMatrix[i][j] == knapsackMatrix[i-1][j]) i--;
		else {
			printf("%d taken\n", i);
			j = j - weight[i];
			i--;
		}
	}
	
	return 0;
	
}
