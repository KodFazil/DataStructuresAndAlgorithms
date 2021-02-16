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
	q->front = q->rear = 0;
}

void display(struct Queue q) {
	int i = q.front + 1;
	do {
		printf("%d ", q.Qptr[i]);
		i = (i+1) % q.size;
	} while(i!=(q.rear+1) % q.size);
	printf("\n");
}

void enqueue(struct Queue *q, int x) {
	if ((q->rear+1) % q->size == q->front) 
		printf("Queue is full\n");
	else {
		q->rear = (q->rear+1) % q->size;
		q->Qptr[q->rear] = x;
	}	
}

int dequeue(struct Queue *q) {
	int x = -1;
	if (q->front == q->rear)
		printf("Queue is empty\n");
	else {
		q->front = (q->front+1) % q->size;
		x = q->Qptr[q->front];
	}
	return x;	
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
	enqueue(&q, 25);
	enqueue(&q, 30);
	display(q);
	printf("Deleted element %d\n", dequeue(&q));
	printf("Deleted element %d\n", dequeue(&q));
	printf("Deleted element %d\n", dequeue(&q));
	display(q);
	return 0;
}
