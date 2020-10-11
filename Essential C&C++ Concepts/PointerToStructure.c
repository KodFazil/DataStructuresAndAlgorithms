#include<stdio.h>
#include<stdlib.h>

struct Student {
	int age;
	int number;
};

int main() {
	
	// pointer to struct 
	struct Student r;
	struct Student *p = &r;
	(*p).age = 5;
	p->number = 15;
	printf("%d ", (*p).age);
	printf("%d", p->number);
	
	// using malloc with structs
	struct Student *pointer;
	pointer = (struct Student *)malloc(sizeof(struct Student));
	return 0;
}
