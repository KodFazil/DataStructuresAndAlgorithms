#include<stdio.h>
#include<stdlib.h>

/* this code below using row major formula, for column major formula
*  this formula should be written m->n*(j-1)-(j-1)*(j-2)/2+i-j inside m.array[] 
*  for n*n matrix, non-zero elements array size is n*(n+1)/2  */

struct matrix {
	int *array;
	int n;
};

void set(struct matrix *m, int i, int j, int x) {
	if (i>=j)
		m->array[i*(i-1)/2+j-1] = x;
}

int get(struct matrix m, int i, int j) {
	if (i>=j)
		return m.array[i*(i-1)/2+j-1];
	return 0;	 
}

void display(struct matrix m) { 
	int i, j;
	for (i=1; i<=m.n; i++) {
		for (j=1; j<=m.n; j++) {
			if (i>=j)
				printf("%d ", m.array[i*(i-1)/2+j-1]); 
			else 
				printf("0 ");	
		}
		printf("\n");
	}
}

int main() {
	
	struct matrix m;
	printf("Enter dimensions of matrix: ");
	scanf("%d", &m.n);
	m.array = (int *)malloc(m.n*(m.n-1)/2*sizeof(int));
	int i, j, x;
	printf("Enter values of matrix:\n");
	for (i=1; i<=m.n; i++) {
		for (j=1; j<=m.n; j++) {
			scanf("%d", &x);
			set(&m, i, j, x); 
		}
	}
	printf("\n");
	display(m);
	printf("\n%d", get(m, 3, 3));
	
	return 0;
}
