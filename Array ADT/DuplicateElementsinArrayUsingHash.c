#include<stdio.h>

void findCountElements(int array[], int n, int max) {
	
	int m = max + 1;
	int hashArray[m];
	int i=0;
	for (i=0; i<m; i++) {
		hashArray[i]=0;
	}
	for (i=0; i<n; i++) {
		hashArray[array[i]]++;
	}
	for (i=0; i<m; i++) {
		if (hashArray[i]>1) {
			printf("%d appearing for %d times\n", i, hashArray[i]);
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
	int max = array[0];
	for (i=1; i<n; i++) {
		if (array[i]>max) {
			max = array[i];
		}
	}
	
	findCountElements(array, n, max);
	
	return 0;
}
