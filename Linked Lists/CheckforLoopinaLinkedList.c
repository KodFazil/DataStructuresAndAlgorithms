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

int isLoop(struct Node *p) {
	struct Node *q;
	q = p;
   	do {
	   	p = p->next;
		q = q->next;
		q = (q!=NULL) ? q->next : q;
	} while (p && q && p!=q);
	if (p == q) 
		 return 1;
	else 
		return 0; 
}

int main() {
	
	struct Node *l1, *l2;
	int array[5] = {1,3,5,7,9};
	create(array, 5);
	display(first);
	l1 = first->next->next;
	l2 = first->next->next->next->next;
	l2->next = l1;
	if (isLoop(first)) {
		printf("\nYes this link has loop");
	}
	else {
			printf("\nNo this link does not have loop");
	}
	
	return 0;
}
