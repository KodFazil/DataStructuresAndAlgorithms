#include<stdio.h>

void unsortedDuplicates(int array[], int n) {
	
	int i, j, count=1;
	for (i=0; i<n-1; i++) {
		count = 1;
		if (array[i]!=-1) {
			for (j=i+1; j<n; j++) {
				if(array[i] == array[j]) {
					count++;
				   	array[j] = -1;
				}
			}
		}
		if (count > 1) {
			printf("Duplicate element %d appearing %d times\n", array[i], count);
		}
	} 
}

void unsortedDuplicatesHash(int array[], int n, int max) {
	int i;
	int m = max+1;
	int bitset[m];
	for(i=0;i<m;i++) bitset[i]=0;
	for (i=0; i<n-1; i++) {
		bitset[array[i]]++;
	}
	for (i=0; i<max+1; i++) {
		if (bitset[i] > 1) {
			printf("Duplicate element %d appearing %d times\n", i, bitset[i]);
		}
	}
}

int main() {
	
	int n = 10; int i;
	int array[10]={8,3,6,4,6,5,6,8,2,7};
	int array2[10]={8,3,6,4,6,5,6,8,2,7};
	printf("First method which's complexity is O(n^2)\n");
	unsortedDuplicates(array, n);
	printf("\nSecond method using hash which's complexity is O(n)\n");
	unsortedDuplicatesHash(array2, n, 8);
	
	return 0;
}
