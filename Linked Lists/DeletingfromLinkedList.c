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

int deleete(struct Node *p, int index) { 
	int x, i;
	struct Node *q = NULL;
	if (index == 1) {
		q = first;
		x = q->data;
		first = first->next;
		free(q); 
	}
	else {
		for (i=0; i<index-1 && p!=NULL; i++) {
			q = p;
			p = p->next;
		}
		if (p) {
			q->next = p->next;
			x = p->data;
			free(p);
		}
	}
	return x;
}

int main() {
	
	int array[5] = {1,3,5,7,9};
	create(array, 5);
	printf("Displaying linked list:\n");
	display(first);
	printf("\nDeleted element at a given index is: %d\n", deleete(first, 4)); 
	display(first);
	
	return 0;
}
