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

int min(struct Node *p) {
	int min = 1000;
	while (p) {
		if (p->data < min) 
			min = p->data;
		p = p->next;	
	}
	return min;
}

int recursiveMin(struct Node *p) {
	int min;
	if (p==NULL)
		return min;
	else {
		min = recursiveMin(p->next);
		if (min < p->data) 
			return min;
		else 
			return p->data;	
	} 
		
			 
}
 

int main() {
	
	int array[5] = {11,32,51,724,92};
	create(array, 5);
	printf("Minimum element in a linked list is: %d\n", min(first));
	printf("Minimum element in a linked list using recursion: %d", recursiveMin(first));
	
	return 0;
}
