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
	first->previous = first->next = NULL;
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

int length(struct Node *p) {
	int length = 0;
	while(p) {
		length++;
		p = p->next;
	}		
	return length;
}

void display(struct Node *p) {
	while (p) {
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

int main() {
	
	int array[5] = {1,2,3,4,5};
	create(array, 5);
	display(first);
	printf("Length of a list is: %d", length(first));
	return 0;
}
