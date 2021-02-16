#include<stdio.h>
#include<stdlib.h>

struct Node {
	int data;
	struct Node *next;
}*front=NULL, *rear=NULL;

void enqueue(int x) {
	
	struct Node *t;
	t = (struct Node *)malloc(sizeof(struct Node));
	if (t==NULL)
		printf("Queue is full\n");
	else {
		if (front == NULL) {
			t->data = x;
			t->next = NULL;
			front=rear=t;
		}
		else {
			t->data = x;
			t->next = NULL;
			rear->next = t;
			rear = t;
		}
	}	
}

int dequeue() {
	struct Node *q;
	int x = -1;
	if (front == NULL)
		printf("Queue is empty\n");
	else {
		q = front;
		front = front->next;
		x = q->data;
		free(q);
	}
	return x;	
}

void display() {
	struct Node *p = front; 
	while (p) {
		printf("%d ", p->data);
		p = p->next;
	} 
	printf("\n");
}

int main() {
	enqueue(5);
	enqueue(10);
	enqueue(15);
	enqueue(20);
	enqueue(25);
	display();
	printf("Deleted element is: %d\n", dequeue());
	printf("Deleted element is: %d\n", dequeue());
	display();
	enqueue(30);
	enqueue(35);
	printf("Deleted element is: %d\n", dequeue());
	display();
	return 0;
}
