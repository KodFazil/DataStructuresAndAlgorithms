#include<stdio.h>
#include<stdlib.h>

struct Node {
	struct Node *lchild;
	int data;
	int height;
	struct Node *rchild; 
}*root=NULL;

int nodeHeight(struct Node *p) {
	int hl, hr;
	hl = (p && p->lchild) ? p->lchild->height : 0;
	hr = (p && p->rchild) ? p->rchild->height : 0;
	return hl > hr ? hl + 1 : hr + 1; 
}

int balanceFactor(struct Node *p) {
	int hl, hr;
	hl = p && p->lchild ? p->lchild->height : 0;
	hr = p && p->rchild ? p->rchild->height : 0;
	return hl - hr;	
}

struct Node * LLRotation(struct Node *p) {
	struct Node *pl = p->lchild;
	struct Node *plr = pl->rchild;
	
	pl->rchild = p;
	p->lchild = plr;
	p->height = nodeHeight(p);
	pl->height = nodeHeight(pl);
	
	if (p==root) 
		pl = root;
	return pl;	
} 

struct Node * LRRotation(struct Node *p) {
	
	struct Node *pl = p->lchild;
	struct Node *plr = pl->rchild;
	
	pl->rchild = plr->lchild;
	p->lchild = plr->rchild;
	
	plr->lchild = plr;
	plr->rchild = p;
	
	pl->height = nodeHeight(pl); 
	plr->height = nodeHeight(plr);
	p->height = nodeHeight(p);
	
	if (p==root)
		plr = root;
	return plr;	
}

struct Node * recursiveInsert(struct Node *p, int key) {
	
	struct Node *t = NULL;
	if (p==NULL) {
		t = (struct Node *)malloc(sizeof(struct Node));
		t->data = key;
		t->height = 1;
		t->lchild = t->rchild = NULL;
		return t;
	}
	else {
		if (key < p->data)
			p->lchild = recursiveInsert(p->lchild, key);
		else if (key > p->data)
			p->rchild = recursiveInsert(p->rchild, key);
		
		p->height = nodeHeight(p);
		if (balanceFactor(p) == 2 && balanceFactor(p->lchild) == 1)
			return LLRotation(p);
		else if (balanceFactor(p) == 2 && balanceFactor(p->lchild) == -1)		
			return LRRotation(p);
		/*else if (balanceFactor(p) == -2 && balanceFactor(p->rchild) == -1)		
			return RRRotation(p);
		else if (balanceFactor(p) == -2 && balanceFactor(p->rchild) == 1)		
			return RLRotation(p);	*/	
		return p;		
	}
	
}

void inorder (struct Node *p) {
	
	if (p) {
		inorder(p->lchild);
		printf("%d ", p->data);
		inorder(p->rchild);
	}
}

int main() {
	
	root = recursiveInsert(root, 30);
	recursiveInsert(root, 10);
	recursiveInsert(root, 40);
	recursiveInsert(root, 20);
	recursiveInsert(root, 50);
	inorder(root);
	
	return 0;
}
