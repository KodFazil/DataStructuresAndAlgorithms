#include<stdio.h>
#include<stdlib.h>

struct Queue {
	int size;
	int front;
	int rear;
	int *Qptr;
};

void create(struct Queue *q, int size) {
	q->size = size;
	q->Qptr = (int *)malloc(q->size*sizeof(int));
	q->front = q->rear = -1;
}

void display(struct Queue q) {
	int i;
	for (i=q.front+1; i<=q.rear; i++) {
		printf("%d ", q.Qptr[i]);
	}
	printf("\n");
}

void enqueue(struct Queue *q, int x) {
	if (q->rear == q->size-1) 
		printf("Queue is full\n");
	else {
		q->rear++;
		q->Qptr[q->rear] = x;
	}	
}

int dequeue(struct Queue *q) {
	int x = -1;
	if (q->front == q->rear)
		printf("Queue is empty\n");
	else {
		q->front++;
		x = q->Qptr[q->front];
	}
	return x;	
}

int isEmpty(struct Queue q) {
	if (q.front == q.rear) 
		return 1;
	else return 0;	
}

int isFull(struct Queue q) {
	if (q.rear == q.size-1) 
		return 1;
	else return 0;	
}

int main() {
	struct Queue q;
	create(&q, 5);
	enqueue(&q, 5);
	enqueue(&q, 10);
	enqueue(&q, 15);
	enqueue(&q, 20);
	display(q);
	printf("Deleted element %d\n", dequeue(&q));
	printf("Deleted element %d\n", dequeue(&q));
	display(q);
	return 0;
}
