#include<stdio.h>

void missingMultipleElements(int array[], int n, int low) {
	int diff = low;
	int i;
	printf("Missing elements are: ");
	for (i=0; i<n; i++) {
		if (diff != array[i] - i) {
			while (diff < array[i] - i) {
				printf("%d ", diff + i);
				diff++;
			}
		}
	}
}

void missingMultipleElements2(int array[], int n, int low, int high) {
	int i;
	int arr[high+1];
	for (i=0; i<high+1; i++) {
		arr[i]=0;
	}
	for (i=0; i<n; i++) {
		arr[array[i]]++;
	}
	printf("\nMissing elements are: ");
	for (i=low; i<=high; i++) {
		if (arr[i]==0) {
			printf("%d ", i);
		}
	}
	
}

int main() {
	
	int array1[11]={6,7,8,9,11,12,15,16,17,18,19};
	missingMultipleElements(array1, 11, 6);
	int array2[10]={3,7,4,9,12,6,1,11,2,10};
	missingMultipleElements2(array2, 10, 1, 12);
	
	
}
