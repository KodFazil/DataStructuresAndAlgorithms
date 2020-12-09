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

struct Node * search(struct Node *p, int key) {
	while (p!=NULL) {
		if (key == p->data) 
			return p;
		p = p->next;
	}
	return NULL;
}
 
struct Node * recursiveSearch(struct Node *p, int key) {
	if (p==0)
		return NULL;
	if (key == p->data)
		return p;
	return recursiveSearch(p->next, key);		
}  

int main() {
	
	struct Node *temp;
	int array[5] = {11,32,51,724,92};
	create(array, 5);
	temp = search(first, 32);
	if (temp != NULL)
		printf("Key %d is found\n", temp->data);
	else 
		printf("Key is not found\n");	
	temp = recursiveSearch(first, 51);
	if (temp != NULL)
		printf("Key %d is found with recursion method\n", temp->data);
	else 
		printf("Key is not found using recursion\n");

	return 0;
}
