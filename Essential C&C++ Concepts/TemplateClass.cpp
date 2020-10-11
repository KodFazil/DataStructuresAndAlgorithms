#include<iostream>
using namespace std;

template<class T>
class Arithmetic {
	private:
		T a;
		T b;
	public:
		Arithmetic(T a, T b);
		T add();
		T sub(); 
};

template<class T>
Arithmetic<T>::Arithmetic(T a1, T b) {
	a = a1; 
	this->b = b;
}

template<class T>
T Arithmetic<T>::add() {
	T c = a + b;
	return c;
}

template<class l>
l Arithmetic<l>::sub() {
	l c = a - b;
	return c;
}

int main() {
	
	// integer data type
	Arithmetic<int> ar(10, 5);
	cout<<"integer add function: "<<ar.add()<<endl;
	cout<<"integer sub function: "<<ar.sub()<<endl;
	
	// float data type
	Arithmetic<float> ar1(10.1, 5.6);
	cout<<"float add function: "<<ar1.add()<<endl;
	cout<<"float sub function: "<<ar1.sub()<<endl;
	
	// double data type
	Arithmetic<double> ar2(10.8, 5.9);
	cout<<"double add function: "<<ar2.add()<<endl;
	cout<<"double sub function: "<<ar2.sub()<<endl;
}
