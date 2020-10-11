#include<stdio.h>
int main() {
	// array declaration
	int array[5];
	// fill the array
	int i;
	for(i=0; i<6; i++) {
		array[i]=i;
	}
	//array initalization
	int array2[6]={5,4,3,2,1,0};
	//printing arrays
	for (i=0; i<6; i++) {
		printf("first arrays number : %d\n", array[i]);
		printf("second arrays number: %d\n", array2[i]);
	}
	return 0;
}
