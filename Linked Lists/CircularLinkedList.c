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
		t = (struct Node *)malloc(sizeof(struct Node));
		t->data = array[i];
		t->next = last->next;
		last->next = t;
		last = t;
	}
}

void display(struct Node *p) {
	do {
		printf("%d ", p->data);
		p = p->next;
	} while(p!=head);
	printf("\n");
}

void recursiveDisplay(struct Node *p) {
	static int flag = 0;
	if (p!=head || flag==0) {
		flag = 1;
		printf("%d ", p->data);
		recursiveDisplay(p->next);
	}
	flag=0;
}

int main() {
	
	int array[5] = {1,2,3,4,5};
	create(array, 5);
	printf("Displaying circular linked list: ");
	display(head);
	printf("Recursive display: ");
	recursiveDisplay(head);
	return 0;
}
