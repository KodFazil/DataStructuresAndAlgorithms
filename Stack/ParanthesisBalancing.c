#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Stack {
	int size;
	int top;
	char *p;
}*st=NULL;

void create(struct Stack *st) {
	st->p = (char *)malloc(st->size*sizeof(char));
	st->top = -1;
}

void display(struct Stack st) {
	int i;
	for (i=st.top; i>=0; i--) 
		printf("| %d |\n", st.p[i]);
	printf("\n");	
}

void push(struct Stack *st, char x) {
	if (st->top == st->size-1)
		printf("Stack overflowed\n");
	else {
		st->top++;
		st->p[st->top] = x;
	}	
}

char pop(struct Stack *st) {
	char x = -1;
	if (st->top == -1) 
		printf("Stack underflowed\n");
	else {
		x = st->p[st->top];
		st->top--;
	}	
	return x;
}

int isEmpty(struct Stack st) {
	if (st.top == -1) 
		return 1;
	return 0;	
}

void isBalanced(char *expr) {
	st = (struct Stack *)malloc(sizeof(struct Stack));
	st->size = strlen(expr);
	create(st);
	int i;
	for (i=0; expr[i]!='\0'; i++) {
		if (expr[i]=='(') 
			push(st, expr[i]);
		else if (expr[i]==')') {
			if (st->top == -1) {
				printf("Not matched\n");
				return; 	
			} 
			else {
				pop(st);
			}	
		}	
	}
	if (st->top == -1) 
		printf("Parenthesis matched\n");
	else 
		printf("Not matched");	
}

int main() { 

	char *expression = "((a+b)*(c-d))";
	isBalanced(expression);
	return 0;
	
}
