#include<stdio.h>

int main() {
	
	int array[10]={1,3,4,5,6,8,9,10,12,14};
	int i=0, j=9, sum=12;
	while(i<j) {
		if (array[i]+array[j]==sum) {
			printf("%d %d\n", array[i], array[j]);
			i++;
			j--;
		}
		else if (array[i]+array[j]>sum) j--;
		else i++;
	}
	
	return 0;
}
