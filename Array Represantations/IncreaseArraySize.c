#include<stdio.h>
#include<stdlib.h>

int main() {  
	int *p, *q, i;
	p = (int *)malloc(5*sizeof(int));
	for (i=0; i<5; i++)
		p[i] = i * 2;
	q = (int *)malloc(10*sizeof(int));
	for (i=0; i<5; i++)
		printf("%d ", p[i]);
	for (i=0; i<5; i++)
		q[i] = p[i];
	free(p);
	p = q;
	q = NULL;
	for (i=5; i<10; i++) 
		p[i] = i*2+1;
	for (i=0; i<10; i++)
		printf("%d ", p[i]);	
	return 0;
}
