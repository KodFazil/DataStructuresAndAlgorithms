#include<stdio.h>
#include<stdlib.h>

struct Node {
	int data;
	struct Node *next;
}*head;

void create(int array[], int n) {
	int i;
	struct Node *t, *last;
	head = (struct Node *)malloc(sizeof(struct Node));
	head->data = array[0];
	head->next = head;
	last = head;
	for (i=1; i<n; i++) {
		t = (struct Node *) malloc (sizeof(struct Node));
		t->data = array[i];
		t->next = last->next;
		last->next = t;
		last = t;
	}
}

void display (struct Node *p) {
	do {
		printf("%d ", p->data);
		p = p->next;
	}while(p!=head);
	printf("\n");
}

void insert(struct Node *p, int index, int x) {
	int i;
	struct Node *t;
	t = (struct Node *)malloc(sizeof(struct Node));
	t->data = x;
	if (index == 0) {
		if (head == NULL) {
			head = t;
			head->next = head;
		}
		else {
			while (p->next != head) 
				p = p->next;
			t->next = p->next;
			p->next = t;
			head = t;	
		}
	}
	else {
		for (i=0; i<index-1; i++) 
			p = p->next;
		t->next = p->next;
		p->next = t;	
	}
	
}

int main() {
	
	int array[5] = {2,4,6,8,10};
	create(array, 5);
	display(head);
	insert(head, 2, 5);
	display(head);
	return 0;
}
