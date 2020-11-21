#include<iostream>
using namespace std;

/* this code below using row major formula, for column major formula
*  this formula should be written m->n*(j-1)-(j-1)*(j-2)/2+i-j inside m.array[] 
*  for n*n matrix, non-zero elements array size is n*(n+1)/2   */

class LowTriMax {
	private:
		int *array;
		int n;
	public:
		LowTriMax() {
			n = 2;
			array = new int[2*(2+1)/2];
		}
		LowTriMax(int n) {
			this->n = n;
			array = new int[n*(n+1)/2];
		}	
		void set(int i, int j, int x);
		int get(int i, int j);
		void display();
		~LowTriMax() {
			delete []array;
		}
};

void LowTriMax::set(int i, int j, int x) {
	if (i>=j) 
		array[i*(i-1)/2+j-1] = x;
}

int LowTriMax::get(int i, int j) {
	if (i>=j)
		return array[i*(i-1)/2+j-1];
	return 0;	
}

void LowTriMax::display() {
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=n; j++) {
			if (i>=j)
				cout<<array[i*(i-1)/2+j-1]<<" ";
			else 
				cout<<"0 ";	
		}
		cout<<endl;
	}
}

int main() {
	
	int n, x;
	cout<<"Enter dimensional of matrix: ";
	cin>>n;
	LowTriMax matris(n);
	cout<<"Enter values of matrix:\n";
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=n; j++) {
			cin>>x;
			matris.set(i, j, x);
		}
	}
	cout<<endl;
	matris.display();
	cout<<"\n"<<matris.get(2, 2);
	
	return 0;
}
