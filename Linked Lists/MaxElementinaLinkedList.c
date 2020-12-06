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

int max(struct Node *p) {
	int max = -1000;
	while (p) {
		if (p->data > max) 
			max = p->data;
		p = p->next;	
	}
	return max;
}

int recursiveMax(struct Node *p) {
	int max = 0;
	if (p==NULL) 
		return max;
	max = recursiveMax(p->next);
	return max > p->data ? max : p->data; 
		
}
 

int main() {
	
	int array[5] = {11,32,51,724,92};
	create(array, 5);
	printf("Maximum element in a linked list is: %d\n", max(first));
	printf("Maximum element in a linked list using recursion: %d", recursiveMax(first));
	
	return 0;
}
