#include<stdio.h>
#include<stdlib.h>

struct Array {
	int *p;
	int size;
	int length;
};

struct statArray {
	int a[20];
	int size;
	int length;
};

void display(struct Array arr) {
	printf("\nThe elements of an array: \n");
	int i;
	for(i=0; i<arr.length; i++) {
		printf("%d ", arr.p[i]);
	}
}

void display2(struct statArray arr) {
	printf("\nThe elements of an array: \n");
	int i;
	for(i=0; i<arr.length; i++) {
		printf("%d ", arr.a[i]);
	}
}

int main() {
	
	struct Array arr;
	printf("Enter the size of an array: ");
	scanf("%d", &arr.size);
	arr.p = (int *)malloc(arr.size*sizeof(int)); 
	printf("\nEnter length of an array: ");
	int n;
	arr.length=0;
	scanf("%d", &n);
	printf("Enter elements:\n");
	int i;
	for(i=0; i<n; i++) {
		scanf("%d", &arr.p[i]);
	}
	arr.length = n;
	display(arr);
	
	struct statArray statArr={{1,2,3,4,5}, 20, 5};
	display2(statArr);
	
	return 0;
} 
