#include<stdio.h>

void insertSortedArray(int array[], int n, int x) {
		int i = n - 1;
		while (x < array[i]) {
			array[i+1] = array[i];
			i--;
		}
		array[i+1] = x;
}

int main() {
	
	int array[8] = {4, 8, 13, 16, 20, 25, 28, 33};
	int n = sizeof(array) / sizeof(array[0]);
	insertSortedArray(array, n, 18);
	int i;
	for (i=0; i<9; i++) {   
		printf("%d ", array[i]);
	}

	return 0;
}
