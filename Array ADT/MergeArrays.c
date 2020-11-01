#include<stdio.h>
#include<stdlib.h>

struct Array {
	int A[10];
	int size;
	int length;
};

void display(struct Array arr) {
	int i;
	for (i=0; i<arr.length; i++) {
		printf("%d ", arr.A[i]);
	}
	printf("\n");
}

struct Array* merge(struct Array arr1, struct Array arr2) {
	int i,j,k;
	i=j=k=0;
	struct Array *arr3 = (struct Array*)malloc(sizeof(struct Array));
	while (i<arr1.length && j<arr2.length) {
		if (arr1.A[i]<arr2.A[j]) {
			arr3->A[k++] = arr1.A[i++]; 
		}
		else {
			arr3->A[k++] = arr2.A[j++];
		}
	}
	
	for (i=i; i<arr1.length; i++) {
		arr3->A[k++] = arr1.A[i];
	}
	for (j=j; j<arr2.length; j++) {
		arr3->A[k++] = arr2.A[j];
	}
	
	arr3->length = arr1.length + arr2.length;
	arr3->size = arr1.size + arr2.size;
	
	return arr3;
}

int main() {
	
	struct Array arr1 = {{1,3,5,7,9}, 10, 5};
	struct Array arr2 = {{2,4,6,8,10}, 10, 5};
	struct Array *arr3;
	arr3 = merge(arr1, arr2);
	display(arr1);
	display(arr2);
	display(*arr3);
	
	return 0;
}
