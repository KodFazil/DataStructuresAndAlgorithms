#include<stdio.h>

void insert(int array[], int n) {
	int i = n;
	int temp = array[i];
	while (i > 1 && temp>array[i/2]) {
		array[i] = array[i/2];
		i /= 2;
	}  
	array[i] = temp;
}

int deleete(int array[], int n) {
	int i, j, x, temp, var;
	var = array[1];
	x = array[n];
	array[1] = array[n];
	array[n] = var;
	i=1; j = i*2;
	while (j<=n-1) {
		if (j<n-1 && array[j+1] > array[j]) 
			j = j+1;
		if (array[i] < array[j]) {
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			i = j;
			j = 2 * j; 
		}	
		else break;
	}
	return var;
}

int main() {
	
	int heapArray[8] = {0, 10, 20, 30, 25, 5, 40, 35};
	int i;
	for (i=2; i<=7; i++) 
		insert(heapArray, i);
	printf("After inserting elements in a heap: ");
	for (i=1; i<=7; i++)
		printf("%d ", heapArray[i]);
	printf("\nDeleting some elements:\n");
	printf("Deleted element is: %d\n", deleete(heapArray, 7));		
	printf("Deleted element is: %d\n", deleete(heapArray, 6));		
	printf("Deleted element is: %d\n", deleete(heapArray, 5));	
	for (i=4; i>1; i--)
		deleete(heapArray, i);	
	printf("After all deletings sorted array (Heap Sort):\n");
	for (i=1; i<=7; i++)
		printf("%d ", heapArray[i]);
	
	return 0;
}
