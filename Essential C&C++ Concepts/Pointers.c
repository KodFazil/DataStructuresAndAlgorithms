#include<stdio.h>
#include<stdlib.h>

int main() {
	
	int a = 5;
	int *p = & a;
	// or here, p = &a;
	printf("address of a pointer: %d value of variable which p points: %d", p, *p);
	// malloc returns a void pointer so we need a type cast it to a int pointer
	int *pointer = (int *)malloc(5*sizeof(int));
	// or here, pointer = (int *)malloc(5*sizeof(int));
	
	return 0;
}
