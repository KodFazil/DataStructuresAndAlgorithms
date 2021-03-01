#include<stdio.h>

void swap(int *x, int *y) {
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

void bubbleSort(int array[], int n) {
	int flag = 0, i, j;
	for (i=0; i<n-1; i++) {
		for (j=0; j<n-1-i; j++) {
			if (array[j] > array[j+1]) {
				swap(&array[j], &array[j+1]);
				flag=1;
			}
		}
		if (flag==0)
			break; 
	} 
	
}


int main() {
	
	int array[10] = {0, 4, 7, 2, 3, 8, 6, 9, 1, 5};
	int n = 10, i;
	bubbleSort(array, n);
	printf("Sorted array is: \n");
	for (i=0; i<n; i++) 
		printf("%d ", array[i]);
	return 0;
}
