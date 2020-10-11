#include<stdio.h>

//call by address
void swap(int *x, int *y) {
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

int main() {
	int a = 10;
	int b = 5; 
	swap(&a, &b);
	printf("a: %d b: %d", a, b);
}

/*
//call by value
void swap(int x, int y) {
	int temp;
	temp = x;
	x = y;
	y = temp;
}

int main() {
	int a = 10;
	int b = 5; 
	swap(a, b);
	printf("a: %d b: %d", a, b);
}
*/

