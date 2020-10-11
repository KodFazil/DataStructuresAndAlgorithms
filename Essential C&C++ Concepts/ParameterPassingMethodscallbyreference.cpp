#include<iostream>
using namespace std;
// call by reference not in c but in c++
void swap(int &x, int &y) {
	int temp;
	temp = x;
	x = y;
	y = temp;
}

int main() {
	int a = 10;
	int b = 5; 
	swap(a, b);
	printf("a: %d b: %d", a, b);
}
