#include<stdio.h>
#include<stdlib.h>

struct Node {
	int data;
	struct Node *next;
}*first = NULL, *second = NULL, *third = NULL;

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

void create2(int array[], int n) {
	int i;
	struct Node *t, *last;
	second = (struct Node *)malloc(sizeof(struct Node));
	second->data = array[0];
	second->next = NULL;
	last = second;
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

void concatenate(struct Node *p, struct Node *q) {
	third = p; // third is a first for concatenate list
	while(p->next != NULL) {
		p = p->next;
	}
	p->next = second;
}

int main() {
	
	int array[5] = {1,3,5,7,9};
	create(array, 5);
	printf("First list\n");
	display(first);
	printf("\n");
	int array2[5] = {2,4,6,8,10};
	create2(array2, 5);
	printf("Second list:\n");
	display(second);
	printf("\n");
	printf("Concatenated list:\n");
	concatenate(first, second);
	display(third);
	
	return 0;
}
