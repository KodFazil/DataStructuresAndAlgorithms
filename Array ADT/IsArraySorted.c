#include<stdio.h>

int isSorted(int array[], int n) {
	int i ,control=1;
	for (i=0; i<n-1; i++) {
		if (array[i] > array[i+1]) {
			return 0;
		}
	}
	return 1;
}

int main() {
	
	int array[8] = {2, 6, 17, 26, 30, 32, 33, 35};
	int n = sizeof(array) / sizeof(array[0]);
	if (isSorted(array, n)) {
		printf("Array is sorted");
	}
	else {
		printf("Array in unsorted");
	}
	
	return 0;
}
