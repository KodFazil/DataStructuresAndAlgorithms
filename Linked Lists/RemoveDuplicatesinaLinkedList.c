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

void removeDuplicates(struct Node *p) {
	
	struct Node *q = p->next;
	while (q != NULL) {
		if (p->data == q->data) {
			p->next = q->next;
			free(q);
			q = p->next;
		}
		else {
			p = q;
			q = q->next;
		}
	}
}

int main() {
	
	int array[9] = {1,1,1,3,5,5,5,7,9};
	create(array, 9);
	display(first);
	printf("\n");
	removeDuplicates(first);
	display(first);
	
	return 0;
}
