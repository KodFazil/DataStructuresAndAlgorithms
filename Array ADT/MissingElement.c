#include<stdio.h>

void missingElement1(int array[], int n, int last) {
	int sum, s, i;
	for (i=0; i<n; i++) {
		sum += array[i];
	}
	s = last*(last+1)/2;
	int diff = s - sum;
	printf("The missing number is: %d",diff);
}

void missingElement2(int array[], int low) {
	int diff = low; 
	int i=0;
	while(diff == low) {
		diff = array[i] - i;
		i++;
	}
	printf("\nThe missing number is: %d\n", diff + i - 2);
} 


int main() {
	
	int array1[9]={1,2,3,4,5,7,8,9,10};
	int n = sizeof(array1) / sizeof(array1[0]); 
	missingElement1(array1, n, 10);
	int array2[9]={7,8,9,10,12,13,14,15,16};
	missingElement2(array2, 7);
	
}
