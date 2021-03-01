#include<stdio.h>

int maxx(int array[], int n) {
	int max = array[0], i;
	for (i=1; i<n; i++) {
		if (array[i] > max)
			max = array[i];
	}
	return max;
}

void countSort(int a[], int n) {
	int i, j, max;
	max = maxx(a, n); 
	int countArray[max+1];
	for (i=0; i<max+1; i++) countArray[i]=0;
	for (i=0; i<n; i++) 
		countArray[a[i]]++;
	i=0, j=0;	
	while (j < max+1) {
		if (countArray[j] > 0) {
			a[i++] = j;
			countArray[j]--;
		} 
		else 
			j++;	
	}	
}

int main() {
	
	int array[] = {4, 2, 8, 1, 9, 6, 5, 0, 7, 3};
	int n = 10, i;
	
	countSort(array, n);
	printf("Sorted array: \n");
	for (i=0; i<n; i++) 
		printf("%d ", array[i]);
	
	return 0;
}
