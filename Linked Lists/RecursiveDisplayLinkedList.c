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

void recursiveDisplay(struct Node *p) {
	if (p!=NULL) {
		printf("%d ", p->data);
		recursiveDisplay(p->next);
	}
}

void reverseRecursiveDisplay(struct Node *p) {
	if (p != NULL) {
		reverseRecursiveDisplay(p->next);
		printf("%d ", p->data);
	}
}

int main() {
	
	int array[5] = {2,4,6,8,10};
	create(array, 5);
	printf("Recursive display of linked list with an order:\n");
	recursiveDisplay(first);
	printf("\nRecursively reverse display of linked list:\n");
	reverseRecursiveDisplay(first);
	return 0;
}
