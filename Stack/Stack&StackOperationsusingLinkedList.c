#include<stdio.h>
#include<stdlib.h>

struct Node {
	int data;
	struct Node *next;
}*top=NULL;

void push(int x) {
	struct Node *t;
	t = (struct Node *)malloc(sizeof(struct Node));
	if (t==NULL) 
		printf("No space\n");
	else {
		t->data = x;
		t->next = top;
		top = t;
	}	
}

int pop() {
	int x = -1;
	struct Node *p;
	if (top==NULL) {
		printf("Stack is empty\n");
	}
	else {
		p = top;
		x = p->data;
		top = top->next;
		free(p);
	}	
	return x;
}

void display() {
	struct Node *p;
	p = top;
	while(p) {
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

int peek(int pos) {
	int i;
	struct Node *p = top;
	for (i=0; p!=NULL && i<pos-1; i++) 
		p = p->next;
	if (p) 
		return p->data;
	else 
		return -1;		
}

int isEmpty() {
	if (top == NULL)
		return 1;
	else 
		return 0;	
}

int isFull() {
	struct Node *p;
	p = (struct Node *)malloc(sizeof(struct Node));
	if (p == NULL)
		return 1;
	else 
		return 0;	
}

int main() { 
	push(10);
	push(15);
	push(20);
	push(25);
	push(30);
	push(35);
	printf("After push:\n");
	display();
	printf("Deleted element: %d\n", pop());
	printf("Deleted element: %d\n", pop());
	printf("Deleted element: %d\n", pop());
	printf("Deleted element: %d\n", pop());
	printf("After pop:\n");
	display();
	printf("Searching element from given index: %d\n", peek(2));
	printf("Is stack empty 1 for true, 0 for false: %d\n", isEmpty());
	printf("Is stack full 1 for true, 0 for false: %d\n", isFull());
	return 0;
}
