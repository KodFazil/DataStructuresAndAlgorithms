#include<stdio.h>

// Basic Array Operations 
// Get, Set, Max, Min, Sum, Avg

struct Array {
	int A[10];
	int size;
	int length;
};

void display(struct Array arr) {
	int i;
	for(i=0; i<arr.length; i++)	{
		printf("%d ", arr.A[i]);
	}
}

int get(struct Array arr, int index) {
	if (index>=0 && index<arr.length) {
		return arr.A[index];
	}
	return -1;
}

void set(struct Array *arr, int index, int x) {
	if (index>=0 && index<arr->length) {
		arr->A[index] = x;	
	} 
}

int max(struct Array arr) {
	int i, max=arr.A[0];
	for(i=0; i<arr.length; i++) {
		if (arr.A[i] > max) {
			max = arr.A[i];
		} 
	}
	return max;
}

int min(struct Array arr) {
	int i, min=arr.A[0];
	for(i=0; i<arr.length; i++) {
		if (arr.A[i] < min) {
			min = arr.A[i];
		}
	}
	return min;
}

int sum(struct Array arr) {
	int sum = 0, i;
	for(i=0; i<arr.length; i++) {
		sum+=arr.A[i];
	}
	return sum;
}

int recSum(struct Array arr, int n) {
	if (n < 0) {
		return 0;
	}
	else {
		return recSum(arr, n-1) + arr.A[n];
	}
}

float avg(struct Array arr) {
	return (float) sum(arr) / arr.length; 
}

int main() {
	
	struct Array arr = {{1,3,5,7,9}, 10, 5};
	display(arr);
	printf("\n%d\n", get(arr, 2));
	set(&arr, 3, 6);
	display(arr);
	printf("\n%d\n", max(arr));
	printf("%d\n", min(arr));
	printf("%d\n", sum(arr));
	printf("%d\n", recSum(arr, arr.length-1));
	printf("%f\n", avg(arr));
	
	return 0;
}
