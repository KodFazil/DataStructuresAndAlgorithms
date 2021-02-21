#include<stdio.h>
#include<stdlib.h>

struct Node {
	struct Node *lchild;
	int data;
	struct Node *rchild;
}*root=NULL;

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

struct Node * recursiveInsert(struct Node *p, int key) {
	
	struct Node *t = NULL;
	if (p==NULL) {
		t = (struct Node *)malloc(sizeof(struct Node));
		t->data = key;
		t->lchild = t->rchild = NULL;
		return t;
	}
	else {
		if (key < p->data)
			p->lchild = recursiveInsert(p->lchild, key);
		else if (key > p->data)
			p->rchild = recursiveInsert(p->rchild, key);
		return p;		
	}
}

int height(struct Node *p) {
	int x, y;
	if (p==NULL) 
		return 0;
	else {
		x = height(p->lchild);
		y = height(p->rchild);
	}	
	return x > y ? x + 1 : y + 1;
}

struct Node *inPrecessor(struct Node *p) {
	while (p && p->lchild) {
		p = p->lchild;
	}
	return p;
}

struct Node *inSuccessor(struct Node *p) {
	while (p && p->rchild) {
		p = p->rchild;	
	}
	return p;
}


struct Node* deletee(struct Node *p, int key) {
	
	if (p == NULL) {
		return NULL;
	}
	if (p->lchild == NULL && p->rchild == NULL) {
		if (p == root)
			root = NULL;
		else {
			free(p);
			return NULL;	
		}
			
	} 
	
	struct Node *q;
	if (key < p->data) 
		p->lchild = deletee(p->lchild, key);
	else if (key > p->data)
		p->rchild = deletee(p->rchild, key);
	else {
		if (height(p->lchild) > height(p->rchild)) {
			q = inPrecessor(p->lchild);
			p->data = q->data;
			p->lchild = deletee(p->lchild, q->data);
		}
		else {
			q = inSuccessor(p->rchild);
			p->data = q->data;
			p->rchild = deletee(p->rchild, q->data);
		}
	}
	
	return p;		
}

int main() {
	
	struct Node *find;
	root = recursiveInsert(root, 30);
	recursiveInsert(root, 10);
	recursiveInsert(root, 40);
	recursiveInsert(root, 20);
	recursiveInsert(root, 50);
	inorder(root);
	deletee(root, 20);
	printf("\nAfter delete:\n");
	inorder(root);
	find = search(30);
	if (find != NULL) 
		printf("\nElement %d found in a tree\n", find->data); 
	else 
		printf("\nElement is not found\n");	
	
	return 0;
}
