#include<iostream>
using namespace std;

class Queue {
	private:
		int size;
		int front;
		int rear;
		int *Qptr;
	public:
		Queue() {  size=10; front=rear=-1; Qptr = new int[size];  };
		Queue(int size) {  this->size=size; front=rear=-1; Qptr = new int[this->size];  };
		void display();
		void enqueue(int x);
		int dequeue();	
};

void Queue::display() {
	int i;
	for (i=front+1; i<=rear; i++)
		cout<<Qptr[i]<<" ";
	cout<<endl;	
}

void Queue::enqueue(int x) {
	if (rear==size-1)
		cout<<"Queue is full"<<endl;
	else {
		rear++;
		Qptr[rear] = x;
	}	
}

int Queue::dequeue() {
	int x = -1;
	if (front == rear)
		cout<<"Queue is empty\n";
	else {
		front++;
		x = Qptr[front];
	}	
	return x;
}

int main() {
	Queue q(5);
	q.enqueue(5);
	q.enqueue(10);
	q.enqueue(15);
	q.enqueue(20);
	q.enqueue(25);
	q.display();
	q.enqueue(30);
	cout<<"Deleted element is: "<<q.dequeue()<<endl;
	cout<<"Deleted element is: "<<q.dequeue()<<endl;
	return 0;
}
