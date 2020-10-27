#include<stdio.h>

struct Array {
	int A[10];
	int size;
	int length;
}; 

void display(struct Array arr) {
	int i;
	for(i=0; i<arr.length; i++) {
		printf("%d ", arr.A[i]);
	}
}

void swap(int *x, int *y) {
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

int linearSearch(struct Array arr, int key) {
	int i;
	for(i=0; i<arr.length; i++) {
		if (key==arr.A[i]) {
			return i;
		}
	}
	return -1;
} 

int impLinearSearch(struct Array *arr, int key) {
	int i;
	for(i=0; i<arr->length; i++) {
		if (key==arr->A[i]) {
			swap(&arr->A[i], &arr->A[i-1]);
			// or swap(&arr->A[i], &arr->A[0]);
			return i;
		}
	}
	return -1;
}

int main() {
	
	struct Array arr = {{0,2,4,6,8,10}, 10, 6};
	display(arr);
	printf("\n%d", linearSearch(arr, 6));
	printf("\n%d", impLinearSearch(&arr, 8));
	printf("\n%d", impLinearSearch(&arr, 6));
	printf("\n%d", impLinearSearch(&arr, 6));
	printf("\n%d", impLinearSearch(&arr, 6));
	printf("\n%d", impLinearSearch(&arr, 6));
	
	return 0;
}
