#include<stdio.h>
#include<stdlib.h>

struct Node {
	int data;
	struct Node *next;
}*first = NULL;

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

void display(struct Node *p) {
	while (p != NULL) {
		printf("%d ", p->data);
		p = p->next;
	}
} 

void recursiveReverse(struct Node *q, struct Node *p) {
	
	if (p != NULL) {
		recursiveReverse(p, p->next);
		p->next = q;
	}
	else {
		first = q;
	}
}

int main() {
	
	int array[9] = {1,1,2,3,4,5,5,7,9};
	create(array, 9);
	display(first);
	recursiveReverse(NULL, first);
	printf("\n");
	display(first);
	
	return 0;
}


