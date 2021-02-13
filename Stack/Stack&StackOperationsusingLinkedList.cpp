#include<iostream>
using namespace std;

class Node {
	public:
		int data;
		Node *next;
};

class Stack {
	private:
		Node *top;
	public:
		Stack() { top = NULL; }
		void push(int x);
		int pop();
		void display();
		int peek(int pos);
		int isEmpty();
		int isFull();	
};

void Stack::push(int x) {
	Node *t = new Node;
	if (t==NULL)
		cout<<"No space, stack is full\n";
	else {
		t->data = x;
		t->next = top;
		top = t;
	}	
} 

int Stack::pop() {
	int x = -1;
	Node *p;
	if (top == NULL)
		cout<<"Stack is empty\n";
	else {
		p = top; 
		top = top->next;
		x = p->data;
		delete p;
	}	
	return x;		
} 

void Stack::display() {
	Node *p;
	p = top;
	while (p) { 
		cout<<p->data<<" ";
		p = p->next;
	} 
	cout<<endl;
}

int Stack::peek(int pos) {
	Node *p = top;
	int i;
	for (i=0; p!=NULL && i<pos-1; i++)
	if (p)
		return p->data;
	else 
		return -1;	
}

int Stack::isEmpty() {
	if (top == NULL)
		return 1;
	return 0;	
}

int Stack::isFull() {
	Node *t = new Node;
	if (t==NULL)
		return 1;
	return 0;	 
}

int main() { 

	Stack st; 
	st.push(1);
	st.push(2); 
	st.push(3); 
	st.push(4);
	st.push(5);
	st.display();
	cout<<"Deleted element: "<<st.pop()<<endl;
	cout<<"Deleted element: "<<st.pop()<<endl;
	cout<<"Deleted element: "<<st.pop()<<endl;
	st.display();
	cout<<"Searching from given index: "<<st.peek(2)<<endl;
	cout<<"Is stack empty 1 for true, 0 for false: "<<st.isEmpty()<<endl;
	cout<<"Is stack full 1 for true, 0 for false: "<<st.isFull()<<endl;
	return 0;
}
