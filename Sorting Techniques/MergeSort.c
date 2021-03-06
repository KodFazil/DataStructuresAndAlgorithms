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

void iterativeMergeSort(int a[], int n) {
	int pass, low, mid, high, i;
	for (pass=2; pass<=n; pass*=2) {
		for (i=0; i+pass-1<n; i=i+pass) {
			low = i;
			high = i+pass-1;
			mid = (low + high) / 2;
			merge(a, low, mid, high);
		}
	}
	if (pass/2 < n) 
		merge(a, 0, pass/2-1, n); 
}

int main() {
	
	int array[] = {4, 2, 8, 1, 9, 6, 5, 0, 7, 3};
	int n = 10, i;
	
	iterativeMergeSort(array, n);
	printf("Sorted array: \n");
	for (i=0; i<n; i++) 
		printf("%d ", array[i]);
	
	return 0;
}
