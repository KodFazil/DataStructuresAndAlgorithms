#include<stdio.h>

struct Array {
	int a[10];
	int size;
	int length;
};

void display(struct Array arr) {
	int i;
	for(i=0; i<arr.length; i++) {
		printf("%d ", arr.a[i]);
	}
}

void append(struct Array *arr, int x) {
	if(arr->length < arr->size) {
		arr->a[arr->length++] = x;
	}
}

void insert(struct Array *arr,int index, int x) {
	if(index>=0 && index <= arr->length) {
		int i;
		for(i=arr->length; i>index; i--) {
			arr->a[i] = arr->a[i-1];
		}
		arr->a[index] = x;
		arr->length++;
	}
}

int Delete(struct Array *arr, int index) {
	int i, x=0; 
	if(index>=0 && index<arr->length) {
		x = arr->a[index];
		for(i=index; i<arr->length-1; i++) {
			arr->a[i] = arr->a[i+1];
		}
		arr->length--;
		return x;
	}
	return 0;
}


int main() {
	
	struct Array arr = {{1,2,3,4,5}, 20, 5};
	display(arr);	
	printf("\nAppend operation:\n");
	append(&arr, 6);
	display(arr);
	printf("\nInsert operation:\n");
	insert(&arr, 2, 78);
	display(arr);
	printf("\nDelete operation:\n");
	printf("%d\n", Delete(&arr, 3));
	display(arr);
	
	return 0;
}
