#include<stdio.h>
#include<stdlib.h>

struct Stack {
	int size;
	int top;
	int *p;
};

void create(struct Stack *st) {
	printf("Enter size of an array: ");
	scanf("%d", &st->size);
	printf("\n");
	st->p = (int *)malloc(st->size*sizeof(int));
	st->top = -1;
}

void display(struct Stack st) {
	int i;
	for (i=st.top; i>=0; i--) 
		printf("| %d |\n", st.p[i]);
	printf("\n");	
}

void push(struct Stack *st, int x) {
	if (st->top == st->size-1)
		printf("Stack overflowed\n");
	else {
		st->top++;
		st->p[st->top] = x;
	}	
}

int pop(struct Stack *st) {
	int x = -1;
	if (st->top == -1) 
		printf("Stack underflowed\n");
	else {
		x = st->p[st->top];
		st->top--;
	}	
	return x;
}

int peek (struct Stack st, int index) {
	int x = -1;
	if (st.top-index+1 < 0) 
		printf("Invalid index\n");
	else 
		x = st.p[st.top-index+1];
	return x; 	 
}

int isEmpty(struct Stack st) {
	if (st.top == -1) 
		return 1;
	return 0;	
}

int isFull(struct Stack st) {
	if (st.top == st.size-1)
		return 1;
	return 0;	
}

int stackTop(struct Stack st) {
	if (!isEmpty(st)) 
		return st.p[st.top];
	else return -1;	
}

int main() { 

	struct Stack st;
	create(&st);
	push(&st, 10);
	push(&st, 15);
	push(&st, 20);
	push(&st, 25);
	display(st);
	printf("After pop\n\n");
	pop(&st); 
	pop(&st);
	display(st);
	printf("Searching element is: %d\n", peek(st, 2));
	printf("Is empty %d\n", isEmpty(st));
	printf("Is full %d\n", isFull(st));
	printf("Top element of the stack: %d\n", stackTop(st));	
	return 0;
	
}
