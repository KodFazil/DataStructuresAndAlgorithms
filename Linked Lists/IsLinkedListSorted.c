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

int isSorted(struct Node *p) { 
	// initially x assigned the minimum number
	int x = -65536; 
	while (p != NULL) {
		if (p->data < x)
			return 0;
		else {
			x = p->data;
			p = p->next;
		}	
	}
	return 1;
}

int main() {
	
	int array[5] = {1,3,5,7,9};
	create(array, 5);
	printf("Displaying linked list:\n");
	display(first);
	printf("\n");
	if (isSorted(first)) 
		printf("Linked list is sorted");
	else 
		printf("Linked list is not sorted");	
	return 0;
}
