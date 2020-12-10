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
	while (p) {
		printf("%d ", p->data);
		p = p->next;
	}
}

void insert(struct Node *p, int index, int x) {
	struct Node *t;
	int i;
	t = (struct Node *)malloc(sizeof(struct Node));
	t->data = x;
	if (index == 0) {
		t->next = first;
		first = t;
	} 
	else {
		for (i=0; i<index-1; i++)
			p = p->next;
		t->next	= p->next;
		p->next = t;	
	}
} 

int main() {
	
	struct Node *temp;
	int array[5] = {11,32,51,724,92};
	create(array, 5);	
	display(first);
	insert(first, 2, 23);
	printf("\n");
	display(first);

	return 0;
}
