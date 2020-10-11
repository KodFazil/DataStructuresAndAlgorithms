#include<stdio.h>

struct Rectangle {
	int length;
	int breadth;
};

void initialize(struct Rectangle *r) {
	r->breadth = 10;
	r->length = 50;
}

void area(struct Rectangle r) {
	printf("%d ", r.breadth * r.length);
}

void changeLength(struct Rectangle *r) {
	r->length = 30;	
}

int main() {
	struct Rectangle r;
	initialize(&r);
	area(r);
	changeLength(&r);
	printf("%d %d ", r.breadth, r.length);
	area(r);
}
