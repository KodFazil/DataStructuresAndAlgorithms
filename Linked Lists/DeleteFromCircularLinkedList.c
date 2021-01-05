#include<stdio.h>
#include<stdlib.h>

struct Node {
	int data;
	struct Node *next;
}*head;

void create(int array[], int n) {
	int i;
	struct Node *t, *last;
	head = (struct Node *) malloc (sizeof(struct Node));
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

void recursiveDisplay(struct Node *p) {
	static int flag = 0;
	if (p != head || flag == 0) {
		flag = 1;
		printf("%d ", p->data);
		recursiveDisplay(p->next);
	}
	flag = 0;
}

int deleete(struct Node *p, int index) {
	int x, i;
	struct Node *q;
	if (index == 1) {
		while (p->next != head) p = p->next;
		x = head->data;
		if (head == p) {
			free(head);
			head = NULL;
		}
		else {
			p->next = head->next;
			free(head);
			head = p->next;
		}
	}
	else {
		for (i=0; i<index-2; i++) 
			p = p->next;
		q = p->next;
		p->next = q->next;
		x = q->data;
		free(q);	
	}
	return x;
}
 
int main() {
	
	int array[5] = {1,3,5,7,9};
	create(array, 5);
	recursiveDisplay(head);
	printf("\n");
	printf("Deleting element from given index is: %d\n", deleete(head, 3));
	recursiveDisplay(head);
	
	return 0;
}
