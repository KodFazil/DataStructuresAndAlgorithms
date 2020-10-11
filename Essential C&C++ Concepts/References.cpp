#include<iostream>
using namespace std;
int main() {
	int a = 5;
	//reference declaring and intialization
	int &r = a;
	cout<<a<<" "<<r<<endl;
	r++; 
	cout<<r<<" "<<a<<endl;  
	a /= 2;
	cout<<r<<" "<<a; 
	return 0;
} 
