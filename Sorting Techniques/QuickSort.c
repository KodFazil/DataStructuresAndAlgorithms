#include<stdio.h>

void swap(int *x, int *y) {
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

int partition(int a[], int l, int h) {
	int pivot = a[l];
	int i=l, j=h;
	do {
		do { i++; } while(a[i] <= pivot);
		do { j--; } while(a[j] > pivot);
		if (i<j) 
			swap(&a[i], &a[j]);	
	} while(i<j);
	swap(&a[l], &a[j]);
	return j;
}

void quickSort(int a[], int l, int h) {
	int j;
	if (l<h) {
		j = partition(a, l, h);
		quickSort(a, l, j);
		quickSort(a, j+1, h);
	}
}

int main() {
	
	int array[] = {4, 2, 8, 1, 9, 6, 5, 0, 7, 3, 65355};
	int n = 11, i;
	
	quickSort(array, 0, n-1);
	printf("Sorted array: \n");
	for (i=0; i<n-1; i++) 
		printf("%d ", array[i]);
	
	return 0;
}
