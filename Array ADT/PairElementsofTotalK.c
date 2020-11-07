#include<stdio.h>

void pairElements(int array[], int n, int k) {
	int i, j;
	for (i=0; i<n-1; i++) {
		for (j=i+1; j<n; j++) {
			if (array[i]+array[j]==k) {
				printf("%d and %d are pair elements\n", array[i], array[j]);
			}
		}
	}
}

void pairElementsHash(int array[], int n, int max, int k) {
	
	int i;
	int bitset[max+1];
	for (i=0; i<max+1; i++) bitset[i]=0;
	for (i=0; i<n; i++) {
		if (bitset[k-array[i]]==1) {
				printf("%d and %d are pair elements\n", array[i], k-array[i]);
		}
		bitset[array[i]]++;
	}
}

int main() {
	
	int n = 10; 
	int array[10]={6,3,8,10,15,7,5,2,9,14};
	printf("Enter total of pair elements:");
	int total;
	scanf("%d", &total);
	printf("First method using for inside for\n");
	pairElements(array, n, total);
	printf("Second method using hash\n");
	pairElementsHash(array, n, 15, total);
	
}
