#include<stdio.h>

int main() {
	int array[] = {-6, 3, -8, 10, 5, -7, -9, 12, -4, 2};
	int n = sizeof(array) / sizeof(array[0]);
	int i = 0, j = n-1;
	while (i<j) {
		while(array[i]<0) {
		i++;
	}	 
		while(array[j]>=0) {
			j--;
	} 
		if(i<j) {
			int temp;
			temp = array[j];
			array[j] = array[i];
			array[i] = temp;		
		}
	}
	for (i=0; i<n; i++) {
		printf("%d ", array[i]);
	} 
	return 0;
}
