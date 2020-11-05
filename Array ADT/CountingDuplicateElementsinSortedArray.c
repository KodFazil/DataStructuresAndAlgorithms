#include<stdio.h>

void countingDuplicateElements(int array[], int n) {
	
	int i,j;
	for (i=0; i<n-1; i++) {
		if (array[i]==array[i+1]) {
			j=i+1;
			while (array[j]==array[i]) {
				j++;
			}
			printf("%d appearing for %d times\n", array[i], j-i);
			i=j;
		}
	}
	
}

int main() {
	
	// ex. array {3,6,8,8,10,12,15,15,15,20}
	printf("Enter size of an array: ");
	int n;
	scanf("%d", &n);
	int array[n];
	printf("Enter elements with order:\n");
	int i;
	for (i=0; i<n; i++) {
		scanf("%d", &array[i]);
	}
	countingDuplicateElements(array, n);
	
}
