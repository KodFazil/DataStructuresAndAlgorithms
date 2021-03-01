#include<stdio.h>

void swap(int *x, int *y) {
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

void selectionSort(int array[], int n) {
	int i, j, minsIndex;
	for (i=0; i<n-1; i++) {
		for (j=minsIndex=i; j<n; j++) {
			if (array[j]<array[minsIndex]) 
				minsIndex = j;
		}
		swap(&array[minsIndex], &array[i]);
	}
}

int main() {
	
	int array[] = {4, 2, 8, 1, 9, 6, 5, 0, 7, 3};
	int n = 10, i;
	
	selectionSort(array, n);
	printf("Sorted array: \n");
	for (i=0; i<n; i++) 
		printf("%d ", array[i]);
	
	return 0;
}
