#include<stdio.h>

void merge(int a[], int l, int mid, int h) {
	// two list in one array, merge them in a same array using auxilary array
	int i=l, j=mid+1, k=l;  
	int b[h+1];
	while(i<=mid && j<=h) {
		if (a[i] < a[j])
			b[k++] = a[i++];
		else 
			b[k++] = a[j++];	
	} 
	for (; i<=mid; i++) b[k++] = a[i]; 
	for (; j<=h; j++) b[k++] = a[j];
	for (i=l; i<=h; i++) a[i] = b[i]; 
}

void recursiveMergeSort(int a[], int l, int h) {
	int mid;
	if (l<h) {
		mid = (l+h)/2;
		recursiveMergeSort(a, l, mid);
		recursiveMergeSort(a, mid+1, h);
		merge(a, l, mid, h);
	}	
}

int main() {
	
	int array[] = {4, 2, 8, 1, 9, 6, 5, 0, 7, 3};
	int n = 10, i;
	
	recursiveMergeSort(array, 0, n-1);
	printf("Sorted array: \n");
	for (i=0; i<n; i++) 
		printf("%d ", array[i]);
	
	return 0;
}
