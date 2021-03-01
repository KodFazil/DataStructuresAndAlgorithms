#include<stdio.h>

void insertionSort(int *arr, int n) {
	int i, j, x;
	for (i=1; i<n; i++) {
		j = i-1;
		x = arr[i];
		while (j>=0 && arr[j]>x) {
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = x;
	}
}

int main() {
	
	int array[] = {4, 2, 8, 1, 9, 6, 5, 0, 7, 3};
	int n = 10, i;
	
	insertionSort(array, n);
	printf("Sorted array: \n");
	for (i=0; i<n; i++) 
		printf("%d ", array[i]);
	
	return 0;
}
