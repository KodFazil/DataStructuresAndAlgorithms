#include<iostream>
using namespace std;

/* this code below using row major formula, for column major formula
*  this formula should be written j*(j-1)/2+i-1 inside m.array[] 
*  for n*n matrix, non-zero elements array size is n*(n+1)/2   */

class UpTriMat {
	private:
		int n;
		int *p;
	public:
		UpTriMat() {
			n = 2;
			p = new int[2*(2+1)/2];
		}
		UpTriMat(int n) {
			this->n = n;
			p = new int[n*(n+1)/2];
		}
		void set(int i, int j, int x);
		int get(int i, int j);
		void display();
		~UpTriMat() {
			delete []p;
		}
};

void UpTriMat::set(int i, int j, int x) {
	if (i<=j) 
		p[n*(i-1)-(i-2)*(i-1)/2+j-i] = x;
}

int UpTriMat::get(int i, int j) {
	if (i<=j)
		return p[n*(i-1)-(i-2)*(i-1)/2+j-i];
	else
		return 0;	
}

void UpTriMat::display() {
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=n; j++) {
			if (i<=j)
				cout<<p[n*(i-1)-(i-2)*(i-1)/2+j-i]<<" ";
			else 
				cout<<"0 ";	
		}
		cout<<endl;
	}
}

int main() {

	cout<<"Enter dimensional of matrix: "<<endl;
	int n;
	cin>>n;
	UpTriMat m(n);
	int x;
	cout<<"Enter values of matrix: "<<endl;
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=n; j++) {
			cin>>x;
			m.set(i, j, x);
		}
	}
	cout<<endl;
 	m.display();
 	cout<<endl;
	cout<<m.get(2, 2);
	return 0;
}
