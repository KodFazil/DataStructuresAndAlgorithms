#include<stdio.h>
#include<stdlib.h>

struct Element {
	int i;
	int j;
	int x;
};

struct Sparse {
	int n;
	int m;
	int num;
	struct Element *ele;
};

void create(struct Sparse *s) {
	int i;
	printf("Enter dimensions: ");
	scanf("%d %d", &s->n, &s->m);
	printf("Enter number of non-zero elements: ");
	scanf("%d", &s->num);
	
	s->ele = (struct Element *)malloc(s->num*(sizeof(struct Element)));
	printf("Enter non-zero elements, i, j, x:\n");
	for (i=0; i<s->num; i++) 
		scanf("%d %d %d", &s->ele[i].i, &s->ele[i].j, &s->ele[i].x);	

}

void display(struct Sparse s) {
	int i, j, k=0;
	for (i=0; i<s.n; i++) {
		for (j=0; j<s.m; j++) {
			if (i == s.ele[k].i && j == s.ele[k].j) 
				printf("%d ", s.ele[k++].x);
			else
				printf("0 ");	
		}
		printf("\n");
	}
}

struct Sparse * add(struct Sparse s1, struct Sparse *s2) {
	struct Sparse *sum;
	int i, j, k;
	i=j=k=0;
	if (s1.n != s2->n || s1.m != s2->m) {
		printf("Wrong dimensions, can not add matrices\n");
		return NULL;
	} 
	sum = (struct Sparse *)malloc(sizeof(struct Sparse));
	sum->ele = (struct Element *)malloc((s1.num + s2->num)*sizeof(struct Element));
	
	/* 
	sum->ele[k] = s1->ele[i] copy all elements of struct such as: 
	sum->ele[k].i = sum->ele[i].i;
	sum->ele[k].j = sum->ele[i].j;
	sum->ele[k].x = sum->ele[i].x; 
	*/ 
	
	while (i<s1.num && j<s2->num) {
		if (s1.ele[i].i < s2->ele[j].i)
			sum->ele[k++] = s1.ele[i++];
		else if (s1.ele[i].i > s2->ele[j].i) 
			sum->ele[k++] = s2->ele[j++];
		else {
			if (s1.ele[i].j < s2->ele[j].j) 
				sum->ele[k++] = s1.ele[i++];
			else if (s1.ele[i].j > s2->ele[j].j)
				sum->ele[k++] = s2->ele[j++];
			else {
				sum->ele[k] = s1.ele[i];
				sum->ele[k++].x = s1.ele[i++].x + s2->ele[j++].x;
			}		
		}		
	}
	
	for (; i<s1.num; i++) sum->ele[k++] = s1.ele[i];
	for (; j<s2->num; j++) sum->ele[k++] = s2->ele[j];	
	
	sum->n = s1.n;
	sum->m = s2->m;
	sum->num = k;
	
	return sum;
};

int main() {
	
	struct Sparse s1, s2, *s3;
	create(&s1);
	create(&s2);
	s3 = add(s1, &s2);
	printf("First matrix:\n");
	display(s1);
	printf("Second matrix:\n");
	display(s2);
	printf("Total matrix:\n");
	display(*s3);
	
	return 0;
}
