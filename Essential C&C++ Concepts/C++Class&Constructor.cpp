#include<iostream>
using namespace std;

class Rectangle {
	private:
		int length;
		int breadth;
	
	public:
		Rectangle();
		Rectangle(int length, int breadth);
		int area();
		int perimeter();
		//getter and setters
		int getLength() {
			return length;
		}
		void setLength(int l) {
			length = l;
		}
		int getBreadth() {
			return breadth;
		} 
		void setBreadth(int b) {
			breadth = b;
		} 
};

// scope resolution operator ::
Rectangle::Rectangle(int l, int b) {
	length = l;
	breadth = b;
}

int Rectangle::area() {
	return length * Rectangle::getBreadth() ;
}

int Rectangle::perimeter() {
	return 2 * (length + breadth);
}

int main() {
	Rectangle r(10, 5);
	cout<<"area: "<<r.area()<<endl;
	cout<<"perimeter: "<<r.perimeter()<<endl;
	cout<<"length: "<<r.getLength()<<" breadth: "<<r.getBreadth()<<endl;
	r.setLength(50);
	r.setBreadth(35);
	cout<<"after changing values respectively area and perimeter "<<r.area()<<" "<<r.perimeter()<<endl;
    cout<<"after changing values: length: "<<r.getLength()<<" breadth: "<<r.getBreadth()<<endl;	

}






