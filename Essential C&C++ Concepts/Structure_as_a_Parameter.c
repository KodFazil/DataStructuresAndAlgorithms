#include<stdio.h>

struct Rectangle {
	int length;
	int breadth;
};

void changeLength(struct Rectangle *r) {
	//they will change value of variable in main cause they called by address
	(*r).length = 20;
	r->breadth = 30;
}
void area(struct Rectangle r) {
	int result = r.breadth * r.length;
	printf("%d ", result);
	// r.breadth++; -> not gonna change variables values in main cause its called by value 
}

int main() {
	struct Rectangle r = {5, 10};
	area(r);
	//printf("%d", r.breadth);
	changeLength(&r);	
	printf("%d ", r.length);	
	printf("%d ", r.breadth);
	//values of variables changed in function changeLength
	area(r);
}
