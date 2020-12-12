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

void insertSorted(struct Node *p, int x) {
	struct Node *t, *q;
	t = (struct Node *)malloc(sizeof(struct Node));
	t->data = x;
	t->next = NULL;
	if (first == NULL)
		t = first;
	else {
		while (p && p->data < x) {
			q = p;
			p = p->next;
		}
		if (p == first) {
			t->next = first;
			first = t;
		}
		else {
			t->next = q->next;
			q->next = t;
		}
	}	
} 


int main() {
	
	int array[5] = {1,3,5,7,9};
	create(array, 5);
	printf("Displaying linked list:\n");
	display(first);
	insertSorted(first, 12);
	printf("\n");
	display(first);
	
	return 0;
}
