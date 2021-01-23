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

int length(struct Node *p) {
	int length = 0;
	while(p) {
		length++;
		p = p->next;
	}		
	return length;
}

int deleete(struct Node *p, int index) {
	int x, i;
	if (index < 1 || index > length(p))
		return -1;
	if (index == 1) {
		first = first->next;
		if (first) first->previous = NULL;
		x = p->data;
		free(p);
	}
	else {
		
		for (i=0; i<index-1; i++) 
			p = p->next;
		p->previous->next = p->next;
		if (p->next) p->next->previous = p->previous;
		x = p->data;
		free(p);
		
	}
	return x;
}

int main() {
	
	int array[] = {1,2,3,4,5};
	create(array, 5);
	recursiveDisplay(first);
	printf("\n"); 
	printf("Deleted element from given index: %d\n", deleete(first, 4));
	recursiveDisplay(first);
	printf("\n"); 
	
	return 0;
}

