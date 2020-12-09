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

struct Node * improvedLSearch(struct Node *p, int key) {
	// tail pointer
	struct Node *q = NULL; 
	while (p) {
		// Move to Head Method
		if (key == p->data) {
			q->next = p->next;
			p->next = first;
			first = p;
			return p;
		}
		q = p;
		p = p->next;
	}
} 

int main() {
	
	struct Node *temp;
	int array[5] = {11,32,51,724,92};
	create(array, 5);	
	temp = improvedLSearch(first, 724);
	if (temp != NULL)
		printf("Key %d is found with move to head method\n", temp->data);
	else 
		printf("Key is not found\n");	
		
	return 0;
}
