#include<stdio.h>

int main() {
	
	int i=0;
	int array[10]={5,18,3,9,-16,2,10,7,-1,4};
	int min,max, n=10; 
	min = max = array[0];
	for (i=1; i<n; i++) {
		if (array[i]>max)
			max = array[i];
		else if (array[i] < min) 
			min = array[i];	
	} 
	printf("Max number is: %d\nMin number is: %d", max, min);
	
	return 0;
}
