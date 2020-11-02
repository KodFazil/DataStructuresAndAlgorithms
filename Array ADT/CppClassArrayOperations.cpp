#include<iostream>
using namespace std;

class Array {
	private:
		int *A;
		int size;
		int length;
	public:
		Array() {
			int size = 10;
			A = new int[10];
			int length = 0;
		}
		Array(int size) {
			int sz = size;
			A = new int[sz];
			int length = 0;
		}
		~Array() {
			delete []A;
		}
		void display();
		void insert(int index, int x);
		int Delete(int index);
		
};

void Array::display() {
	for (int i=0; i<length; i++) {
		cout<<A[i]<<" ";
	}
	cout<<endl;
}

void Array::insert(int index, int x) {
	if (index>=0 && index<=length) {
		for (int i=length; i>=index; i--) {
			A[i+1] = A[i];
		} 
		A[index] = x;
		length++;
	}
}

int Array::Delete(int index) {
	int x = 0;
	if (index>=0 && index<length) {
		x = A[index];
		for (int i=index; i<length-1; i++) {
			A[i] = A[i+1]; 
		}
		length--;
	}
	return x;
}

int main() {
	
	Array arr(10);
	arr.insert(0,4);
	arr.insert(1,5);
	arr.insert(2,6);
	arr.display();
	arr.Delete(1);
	arr.display();
	
	return 0;
}
