#include<stdio.h>
#include<stdlib.h>

struct Node {
	struct Node *lchild;
	int data;
	struct Node *rchild;
}*root=NULL;

void insert (int key) {
	struct Node *t = root;
	struct Node *r = NULL, *p;
	if (root == NULL) {
		p = (struct Node *)malloc(sizeof(struct Node));
		p->data = key;
		p->lchild = p->rchild = NULL;
		root = p;
		return; 
	}
	else {
		
		while (t!=NULL) {
			r = t;
			if (key < t->data) 
				t = t->lchild;
			else if (key > t->data) 
				t = t->rchild;
			else return;		
		}
		p = (struct Node *)malloc(sizeof(struct Node));
		p->data = key;
		p->lchild = p->rchild = NULL;
		
		if (key < r->data) 
			r->lchild = p;
		else 
			r->rchild = p;	
	}
}

void inorder (struct Node *p) {
	
	if (p) {
		inorder(p->lchild);
		printf("%d ", p->data);
		inorder(p->rchild);
	}
}

struct Node* search(int key) {
	
	struct Node *t = root;
	
	while (t) {
		if (key == t->data) 
			return t;
		else if (key < t->data)
			t = t->lchild;
		else 
			t = t->rchild;		
	}
	return NULL;
}


int main() {
	
	struct Node *find;
	insert(30);
	insert(10);
	insert(40);
	insert(20);
	insert(50);
	inorder(root);
	find = search(30);
	if (find != NULL) 
		printf("\nElement %d found in a tree\n", find->data); 
	else 
		printf("\nElement is not found\n");	
	
	return 0;
}
