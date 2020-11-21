#include<iostream>
using namespace std;

class Diagonal {
	
	private: 
		int n;
		int *array;
	
	public:
		
		Diagonal() {
			n = 2;
			array = new int[n];
		}
		
		Diagonal(int n) {
			this->n = n;
			array = new int[n];
		}
		
		void set(int i, int j, int x) {
			if (i == j) 
				array[i-1] = x;
		}
		
		int get(int i, int j) {
			if (i == j)
				return array[i-1];
			return 0;
		}
		
		void display();
		
		~Diagonal() {
			delete []array;
		}
};

/*void Diagonal::set(int i, int j, int x) {
	if (i == j) 
		array[i-1] = x;
} 

int Diagonal::get(int i, int j) {
	if (i == j)
		return array[i-1];
	return 0;		
} */

void Diagonal::display() {
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			if (i == j)
				cout<<array[i]<<" ";
			else 
				cout<<"0 ";
		}
		cout<<endl;
	}
}

int main() {
	
	//Diagonal dia;
	Diagonal dia(4); 
	
	dia.set(1,1,2);
	dia.set(2,2,4);
	dia.set(3,3,6);
	dia.set(4,4,8);
	
	dia.display(); 
	
	cout<<dia.get(1,1);
	
	return 0;
}
