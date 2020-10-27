#include<stdio.h>

int binarySearch(int array[], int key, int n) {
	
	int l = 0;
	int h = n; 
	int m;
	
	while(l<=h) {
		m = (l+h) / 2;
		if (array[m] == key) {
			return m;
		}	
		else if (key < array[m]) {
			h = m - 1;
		}
		else {
			l = m + 1;
		}
	}
	return -1;
}

int recBinarySearch(int arr[], int l, int h, int key) {
	
	int m;
	if (l<=h) {
		m = (l+h) / 2;
		if (arr[m]==key) {
			return m;
		}
		else if (key < arr[m]) {
			return recBinarySearch(arr, l, m-1, key);
		}
		else {
			return recBinarySearch(arr, m+1, h, key);
		}
	}
	return -1;
}

int main() {
	
	int array[6]={1,3,5,7,9,11};
	int n = (sizeof(array) / sizeof(array[0]));
	int i;
	for(i=0; i<6; i++) {
		printf("%d ", array[i]);
	}
	
	printf("\n%d", binarySearch(array, 9, n - 1));
	printf("\n%d", recBinarySearch(array, 0, n-1, 5));
	
	return 0;
}
