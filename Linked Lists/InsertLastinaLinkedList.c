#include<stdio.h>
#include<stdlib.h>

struct Node {
	int data;
	struct Node *next;
}*first = NULL;

void display(struct Node *p) {
	while (p != NULL) {
		printf("%d ", p->data);
		p = p->next;
	}
} 

void insertLast(int x) {
	struct Node *t, *last;
	t = (struct Node *)malloc(sizeof(struct Node));
	last = first;
	t->data = x;
	t->next = NULL;
	if (first == NULL) {
		first = t;
	}
	else {
		while (last->next != NULL)
			last = last->next;
		last->next = t;
	}	
} 

int main() {
	
	insertLast(12);
	display(first);
	printf("\n");
	insertLast(24);
	display(first);
	printf("\n");
	insertLast(36);
	display(first);
	printf("\n");
	insertLast(72);
	display(first);		
	
	return 0;
}
