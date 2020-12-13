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

void reverseLinkedList(struct Node *p, int n) {
	int *ptr, i = 0;
	ptr = (int *)malloc(n * sizeof(int));
	while (p) {
		ptr[i] = p->data;
		i++;
		p = p->next;
	}
	p = first;
	i--;
	while (p) {
		p->data = ptr[i];
		i--;
		p = p->next;
	}
}

int main() {
	
	int array[9] = {1,1,1,3,5,5,5,7,9};
	create(array, 9);
	display(first);
	reverseLinkedList(first, 9);
	printf("\n");
	display(first);
	
	return 0;
}
