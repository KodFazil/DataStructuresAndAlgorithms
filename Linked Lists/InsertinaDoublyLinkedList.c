#include<stdio.h>
#include<stdlib.h>

struct Node {
	struct Node *previous;
	int data;
	struct Node *next;
}*first;

void create(int array[], int n) {
	int i;
	struct Node *t, *last;
	first = (struct Node *)malloc(sizeof(struct Node));
	first->data = array[0];
	first->next = first->previous = NULL;
	last = first;
	for (i=1; i<n; i++) {
		t = (struct Node *)malloc(sizeof(struct Node));
		t->data = array[i];
		t->next = last->next;
		t->previous = last;
		last->next = t;
		last = t;
	}
}

void recursiveDisplay(struct Node *p) {
	if (p != NULL) {
		printf("%d ", p->data);
		recursiveDisplay(p->next);
	}	
}

void insert(struct Node *p, int index, int x) {
	int i;
	struct Node *t;
	t = (struct Node *)malloc(sizeof(struct Node));
	t->data = x;
	if (index == 0) {
		t->previous = NULL;
		t->next = first;
		first->previous = t;
		first = t;
	}	
	else {
		for (i=0; i<index-1; i++) 
			p = p->next;
		t->next = p->next;
		t->previous = p;
		if (p->next)
			p->next->previous = t;
		p->next = t;	
	}
}

int main() {
	
	int array[] = {1,2,3,4,5};
	create(array, 5);
	recursiveDisplay(first);
	printf("\n"); 
	insert(first, 5, 7);
	recursiveDisplay(first);
	printf("\n"); 
	
	return 0;
}

