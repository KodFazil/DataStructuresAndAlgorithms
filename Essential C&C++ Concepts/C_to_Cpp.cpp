#include<iostream>
using namespace std;

class Rectangle {
	private:
	int length;
	int breadth; 

/*void initialize() {
	breadth = 10;
	length = 50;
} */
	public:
	Rectangle(int l, int b) {
	breadth = l;
	length = b;
}

void area() {
	cout<<breadth * length<<endl;
}

void changeLength() {
	length = 30;	
} 

};

int main() {
    Rectangle r(10, 50);
	//r.initialize();
	r.area();
	r.changeLength(); 
	//cout<<r.breadth<<" "<<r.length<<endl;
	r.area();
}
