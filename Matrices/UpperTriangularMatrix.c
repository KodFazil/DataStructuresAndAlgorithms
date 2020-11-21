#include<stdio.h>
#include<stdlib.h>

/* this code below using row major formula, for column major formula
*  this formula should be written j*(j-1)/2+i-1 inside m.array[] 
*  for n*n matrix, non-zero elements array size is n*(n+1)/2   */

struct upTriMat {
	int *p;
	int n;
};

void set(struct upTriMat *m, int i, int j, int x) {
	if (i<=j) 
		m->p[m->n*(i-1)-(i-2)*(i-1)/2+j-i] = x;
}

int get(struct upTriMat m, int i, int j) {
	if (i<=j) 
		return m.p[m.n*(i-1)-(i-2)*(i-1)/2+j-i]; 
	else 
		return 0;
}

void display(struct upTriMat m) {
	int i, j;
	for (i=1; i<=m.n; i++) {
		for (j=1; j<=m.n; j++) {
			if (i<=j) 
				printf("%d ", m.p[m.n*(i-1)-(i-2)*(i-1)/2+j-i]);
			else 
				printf("0 ");	
		}
		printf("\n");
	}
}


int main() {
	
	struct upTriMat m;
	printf("Enter dimensional of matrix: ");
	scanf("%d", &m.n);
	m.p = (int *)malloc(m.n*(m.n+1)/2*sizeof(int));
	printf("Enter values of matrix:\n");
	int i, j, x;
	for (i=1; i<=m.n; i++) {
		for (j=1; j<=m.n; j++) {
			scanf("%d", &x);
			set(&m, i, j, x);	
		}
	}
	printf("\n");
	display(m);
	printf("\n%d", get(m, 2, 3));
	return 0;
}
