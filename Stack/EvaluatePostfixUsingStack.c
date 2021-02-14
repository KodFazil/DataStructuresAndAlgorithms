#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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

int precedence(char x) {
	if (x=='+' || x=='-') 
		return 1;
	else if (x=='*' || x=='/')
		return 2;
	else return 0;		
}

int isOperand(char x) {
	if (x=='+' || x=='-' || x=='*' || x=='/') 
		return 0;
	return 1;	
}

char * infixToPostfix(char *infix) {
	
	int i=0, j=0;
	char *postfix;
	int len = strlen(infix);
	postfix = (char *)malloc((len+2)*sizeof(char));
	
	while (infix[i]!='\0') {
		if (isOperand(infix[i]))
			postfix[j++] = infix[i++];
		else {
			if (precedence(infix[i]) > precedence(top->data))
				push(infix[i++]);
			else 
				postfix[j++] = pop();
		}	
	}
	while (top!=NULL) 
		postfix[j++] = pop();
	postfix[j] = '\0';
	return postfix;	
}

int evaluate(char *postfix) {
	int i;
	int x1, x2, result;
	for (i=0; postfix[i]!='\0'; i++) {
		if (isOperand(postfix[i]))
			push(postfix[i]-'0');
		else {
			x2 = pop(); 
			x1 = pop();
			switch(postfix[i]) {
				case '+' : result = x1 + x2; break;
				case '-' : result = x1 - x2; break;
				case '*' : result = x1 * x2; break;
				case '/' : result = x1 / x2; break;
			}
			push(result);
		}	
	}
	return pop();
}

int main() { 

	char *postfix = "234*+82/-"; 
	printf("Result is: %d", evaluate(postfix));
	return 0;
}
