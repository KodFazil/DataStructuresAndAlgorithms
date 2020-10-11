#include<stdio.h>

//structure declaration
struct Rectangle {
	int length;
	int breadth;
};

//another structure declaration
struct Student {
	// can't do -> int age = 20;
	int age;
	int number;
};

int main() {
	// struct initialization
	struct Rectangle r = {10,5};
	printf("Area of this rectangle is %d: \n", r.breadth * r.length);
	r.breadth = 7;
	r.length = 8;
	printf("New area of this rectangle is %d: \n", r.breadth * r.length);
	
	// struct array initialization
	struct Student s[3] = {{0, 1}, {2, 3}}; 
	int i;
	for (i=0; i<2; i++) {
		printf("Students age: %d and number: %d\n", s[i].age, s[i].number);
	}
	
	//struct array assigning
	struct Student student[5];
	student[1].age = 5;
	student[1].number = 15; 
	printf("Second struct student respectively age and number: %d, %d", student[1].age, student[1].number);
	
	
	return 0;
}
