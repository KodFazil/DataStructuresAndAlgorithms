#include<stdio.h>
#include<stdlib.h>

void printArray(int *array, int n) {
	int i;
	for (i=0; i<n; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");
} 

void reverse(int array[], int n) {
	int i; 
	int arrayB[n];
	for (i=0; i<n; i++) {
		arrayB[n-i-1] = array[i]; 
	}
	for (i=0; i<n; i++) {
		array[i] = arrayB[i];
	}
}

void reverse2(int array[], int n) {
	int *p, i, j;
	p = (int *)malloc(n*sizeof(int));
	for (i=n-1, j=0; i>=0; i--, j++) {
		p[j] = array[i]; 
	}
	for (i=0; i<n; i++) {
		array[i] = p[i];
	}
}

void swap(int *x, int *y) {
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

void reverse3(int *array, int n) {
	int i, j;
	for (i=0, j=n-1; i<j; i++, j--) {
		swap(&array[i], &array[j]);
	}	
}

int main() {
	int array[] = {2,4,6,8,10};
	int n = sizeof(array) / sizeof(array[0]);
	int i;
	printArray(array, n);
	reverse(array, n);
	printArray(array, n);
	reverse2(array, n);
	printArray(array, n);
	reverse3(array, n);
	printArray(array, n);
	return 0;
}
