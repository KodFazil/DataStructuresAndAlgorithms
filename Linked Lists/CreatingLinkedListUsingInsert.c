#include<stdio.h>
#include<stdlib.h>

struct Node {
	int data;
	struct Node *next;
} * first = NULL;

void insert(struct Node *p, int index, int x) {
	int i;
	struct Node *t;
	t = (struct Node *)malloc(sizeof(struct Node));
	t->data = x;
	if (index == 0) {
		t->next = first;
		first = t;
	}
	else {
		for (i=0; i<index-1; i++) 
			p = p->next;
		t->next = p->next;
		p->next = t;
	}
}

void recursiveDisplay(struct Node *p) {
	if (p!=0) {
		printf("%d ", p->data);
		recursiveDisplay(p->next);
	}	 
}

int main() {
	
	insert(first, 0, 5);
	recursiveDisplay(first);
	printf("\n");
	insert(first, 1, 10);
	recursiveDisplay(first);
	printf("\n");
	insert(first, 2, 15);
	recursiveDisplay(first);
	printf("\n");
	insert(first, 3, 135);
	recursiveDisplay(first);
	printf("\n");
	
	return 0;
}
