#include<stdio.h>
#include<stdlib.h>

struct Node {
	int data;
	struct Node *next;
}*first=NULL;

void create(int array[], int n) {
	int i;
	struct Node *t, *last;
	first = (struct Node *)malloc(sizeof(struct Node));
	first->data = array[0];
	first->next = NULL;
	last = first;
	for (i=1; i<n; i++) { 
		t = (struct Node *)malloc(sizeof(struct Node));
		t->data = array[i];
		t->next = NULL;
		last->next = t;
		last = t; 
	}
}

int sum(struct Node *p) {
	int sum = 0;
	while (p!=NULL) {
		sum += p->data;
		p = p->next;
	}
	return sum;
}

int recursiveSum(struct Node *p) {
	if (!p) 
		return 0;
	else 
		return recursiveSum(p->next) + p->data;	
} 

int main() {
	
	int array[7] = {2,4,6,8,10,12,14};
	create(array, 7);
	printf("Sum of all emenets in a linked list %d ", sum(first));
	printf("\nSum of all elements in a linked list %d ", recursiveSum(first));
	return 0;
}
