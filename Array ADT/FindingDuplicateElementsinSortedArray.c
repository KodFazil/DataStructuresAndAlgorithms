#include<stdio.h>

void findingDuplicateElements(int array[], int n) {
	int lastDuplicate = 0;
	int i;
	for (i=0; i<n-1; i++) {
		if (array[i]==array[i+1] && array[i]!=lastDuplicate) {
			printf("Duplicate element is: %d\n", array[i]);
			lastDuplicate=array[i]; 
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
	findingDuplicateElements(array, n);
	
	return 0;
}
